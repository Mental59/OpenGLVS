#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <chrono>
#include "Matrix.h"
#include "Vector.h"

using namespace std;

GLFWwindow *g_window;

GLuint g_shaderProgram;
GLint g_uMVP;
GLint g_uMV;
GLint g_uN;
GLint g_uParams;

GLfloat params[] = { -0.05f, -90.0f, -5.0f };
int sign = 1;

chrono::time_point<chrono::system_clock> g_callTime;

class Model
{
public:
    GLuint vbo;
    GLuint ibo;
    GLuint vao;
    GLsizei indexCount;
};

Model g_model;

GLfloat* createMesh(const int n)
{
    GLfloat* mesh = new GLfloat[2 * n * n];
    GLfloat k2 = 0;

    for (int i = 0; i < 2 * n * n; i += 2 * n)
    {
        GLfloat k1 = 0;
        for (int j = 0; j < 2 * n; j+=2)
        {
            mesh[i + j] = k1;
            mesh[i + j + 1] = k2;
            k1 += 1.0f / (GLfloat)(n - 1);
        }
        k2 += 1.0f / (GLfloat)(n - 1);
    }

    return mesh;
}

GLuint createShader(const GLchar *code, GLenum type)
{
    GLuint result = glCreateShader(type);

    glShaderSource(result, 1, &code, NULL);
    glCompileShader(result);

    GLint compiled;
    glGetShaderiv(result, GL_COMPILE_STATUS, &compiled);

    if (!compiled)
    {
        GLint infoLen = 0;
        glGetShaderiv(result, GL_INFO_LOG_LENGTH, &infoLen);
        if (infoLen > 0)
        {
            char* infoLog = (char*)alloca(infoLen);
            glGetShaderInfoLog(result, infoLen, NULL, infoLog);
            cout << "Shader compilation error" << endl << infoLog << endl;
        }
        glDeleteShader(result);
        return 0;
    }
    
    return result;
}

GLuint createProgram(GLuint vsh, GLuint fsh)
{
    GLuint result = glCreateProgram();

    glAttachShader(result, vsh);
    glAttachShader(result, fsh);
    
    glLinkProgram(result);

    GLint linked;
    glGetProgramiv(result, GL_LINK_STATUS, &linked);
    
    if (!linked)
    {
        GLint infoLen = 0;
        glGetProgramiv(result, GL_INFO_LOG_LENGTH, &infoLen);
        if (infoLen > 0)
        {
            char *infoLog = (char *)alloca(infoLen);
            glGetProgramInfoLog(result, infoLen, NULL, infoLog);
            cout << "Shader program linking error" << endl << infoLog << endl;
        }
        glDeleteProgram(result);
        return 0;
    }

    return result;
}

bool createShaderProgram()
{
    g_shaderProgram = 0;

    const GLchar vsh[] = // VERTEX SHADER
    "#version 330\n"
    ""
    "layout(location = 0) in vec2 a_position;"
    ""
    "uniform mat4 u_mvp;"
    "uniform mat4 u_mv;"
    "uniform mat3 u_n;"
    "uniform vec3 u_params;"
    ""
    "out vec3 v_normal;"
    "out vec3 v_pos;"
    ""
    "float f(vec2 p)"
    "{"
    "   float a = u_params[0];"
    "   float b = u_params[1];"
    "   float c = u_params[2];"
    "   float squaresum = p[0] * p[0] + p[1] * p[1];"
    "   return a * cos(b * squaresum) * exp(c * squaresum);"
    "}"
    ""
    "vec3 gradient(vec2 p)"
    "{"
    "   float a = u_params[0];"
    "   float b = u_params[1];"
    "   float c = u_params[2];"
    "   float squaresum = p[0] * p[0] + p[1] * p[1];"
    "   float temp = 2.0 * a * exp(c * squaresum) * (c * cos(b * squaresum) - b * sin(b * squaresum));"
    "   return vec3(-p[0] * temp, 1.0, -p[1] * temp);"
    "}"
    ""
    "void main()"
    "{"
    "   float y = f(a_position);"
    "   vec4 p0 = vec4(a_position[0], y, a_position[1], 1.0);"
    "   v_normal = transpose(inverse(u_n)) * normalize(gradient(a_position));"
    "   v_pos = vec3(u_mv * p0);"
    "   gl_Position = u_mvp * p0;"
    "}"
    ;

    const GLchar fsh[] = // FRAGMENT SHADER
    "#version 330\n"
    ""
    "in vec3 v_normal;"
    "in vec3 v_pos;"
    ""
    "layout(location = 0) out vec4 o_color;"  
    ""
    "void main()"
    "{"
    "   vec3 color = vec3(0.0, 1.0, 1.0);"
    ""
    "   vec3 E = vec3(0.0, 0.0, 0.0);"
    "   vec3 L = vec3(5.0, 5.0, 0.0);"
    "   float S = 90.0;"
    ""
    "   vec3 n = normalize(v_normal);"
    "   vec3 l = normalize(v_pos - L);"
    ""
    "   float d = max(dot(n, -l), 0.1);"
    ""
    "   vec3 e = normalize(E - v_pos);"
    "   vec3 h = normalize(-l + e);"
    ""
    "   float s = pow(max(dot(n, h), 0.0), S);"
    ""
    "   o_color = vec4(color * d + s * vec3(1.0, 1.0, 1.0), 1.0);"
    "}"
    ;

    GLuint vertexShader, fragmentShader;

    vertexShader = createShader(vsh, GL_VERTEX_SHADER);
    fragmentShader = createShader(fsh, GL_FRAGMENT_SHADER);

    g_shaderProgram = createProgram(vertexShader, fragmentShader);

    g_uMVP = glGetUniformLocation(g_shaderProgram, "u_mvp");
    g_uN = glGetUniformLocation(g_shaderProgram, "u_n");
    g_uMV = glGetUniformLocation(g_shaderProgram, "u_mv");
    g_uParams = glGetUniformLocation(g_shaderProgram, "u_params");

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return g_shaderProgram != 0;
}

bool createModel()
{
    const int n = 2000;

    GLfloat* vertices = createMesh(n);

    const int indices_size = (n - 1) * (n - 1) * 6;

    GLuint* indices = new GLuint[indices_size];

    int k = 0;
    for (int i = 0; i < indices_size; )
    {
        for (int count = 0; count < n - 1; count++, i += 6)
        {
            indices[i] = k;
            indices[i + 1] = k + n;
            indices[i + 2] = k + 1;
            indices[i + 3] = k + n;
            indices[i + 4] = k + n + 1;
            indices[i + 5] = k + 1;
            k++;
        }
        k++;
    }

    for (int i = 0; i < 2 * n * n; i += 2)
    {
        vertices[i] -= 0.5;
        vertices[i + 1] -= 0.5;
    }

    glGenVertexArrays(1, &g_model.vao);
    glBindVertexArray(g_model.vao);

    glGenBuffers(1, &g_model.vbo);
    glBindBuffer(GL_ARRAY_BUFFER, g_model.vbo);
    glBufferData(GL_ARRAY_BUFFER, 2 * n * n * sizeof(GLfloat), vertices, GL_STATIC_DRAW);
    
    glGenBuffers(1, &g_model.ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, g_model.ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices_size * sizeof(GLuint), indices, GL_STATIC_DRAW);

    delete[] vertices;
    delete[] indices;

    g_model.indexCount = indices_size;
    
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (const GLvoid *)0);

    return g_model.vbo != 0 && g_model.ibo != 0 && g_model.vao != 0;
}

bool init()
{
    // Set initial color of color buffer to white.
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glEnable(GL_DEPTH_TEST);

    return createShaderProgram() && createModel();
}

void reshape(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void draw(double delta)
{
    cout << "params[1] = " << params[1] << endl;
   
    params[1] += delta * 12.0 * sign;

    // Clear color buffer.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUseProgram(g_shaderProgram);
    glBindVertexArray(g_model.vao);

    static Matrix4 S = createScaleMatrix(0.5f, 0.5f, 0.5f);

    static Matrix4 T = createTranslateMatrix(-0.03f, -0.1f, -1.0f);

    static Matrix4 Ry = createRotateYMatrix(20.0f);

    static Matrix4 Rx = createRotateXMatrix(40.0f);

    static Matrix4 Rz = createRotateZMatrix(30.0f);

    static Matrix4 MV = T * S * Rx * Ry;

    static Matrix3 UN = getMainMinor(MV);

    static Matrix4 P = createPerspectiveProjectionMatrix(100.0f, 0.01f, 40.0f, 4, 3);

    static Matrix4 MVP = P * MV;

    glUniformMatrix4fv(g_uMVP, 1, GL_TRUE, MVP.elements);
    glUniformMatrix3fv(g_uN, 1, GL_TRUE, UN.elements);
    glUniformMatrix4fv(g_uMV, 1, GL_TRUE, MV.elements);
    glUniform3fv(g_uParams, 1, params);

    glDrawElements(GL_TRIANGLES, g_model.indexCount, GL_UNSIGNED_INT, NULL);

    if (abs(params[1]) > 90.0)
        sign *= -1;
}

void cleanup()
{
    if (g_shaderProgram != 0)
        glDeleteProgram(g_shaderProgram);
    if (g_model.vbo != 0)
        glDeleteBuffers(1, &g_model.vbo);
    if (g_model.ibo != 0)
        glDeleteBuffers(1, &g_model.ibo);
    if (g_model.vao != 0)
        glDeleteVertexArrays(1, &g_model.vao);
}

bool initOpenGL()
{
    // Initialize GLFW functions.
    if (!glfwInit())
    {
        cout << "Failed to initialize GLFW" << endl;
        return false;
    }

    // Request OpenGL 3.3 without obsoleted functions.
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create window.
    g_window = glfwCreateWindow(800, 600, "OpenGL Test", NULL, NULL);
    if (g_window == NULL)
    {
        cout << "Failed to open GLFW window" << endl;
        glfwTerminate();
        return false;
    }

    // Initialize OpenGL context with.
    glfwMakeContextCurrent(g_window);

    // Set internal GLEW variable to activate OpenGL core profile.
    glewExperimental = true;

    // Initialize GLEW functions.
    if (glewInit() != GLEW_OK) 
    {
        cout << "Failed to initialize GLEW" << endl;
        return false;
    }

    // Ensure we can capture the escape key being pressed.
    glfwSetInputMode(g_window, GLFW_STICKY_KEYS, GL_TRUE);

    // Set callback for framebuffer resizing event.
    glfwSetFramebufferSizeCallback(g_window, reshape);

    return true;
}

void tearDownOpenGL()
{
    // Terminate GLFW.
    glfwTerminate();
}

int main()
{   
    // Initialize OpenGL
    if (!initOpenGL())
        return -1;

    // Initialize graphical resources.
    bool isOk = init();

    if (isOk)
    {
        g_callTime = chrono::system_clock::now();
        // Main loop until window closed or escape pressed.
        while (glfwGetKey(g_window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(g_window) == 0)
        {
            auto callTime = chrono::system_clock::now();
            chrono::duration<double> elapsed = callTime - g_callTime;
            g_callTime = callTime;

            // Draw scene.
            draw(elapsed.count());

            // Swap buffers.
            glfwSwapBuffers(g_window);
            // Poll window events.
            glfwPollEvents();
        }
    }

    // Cleanup graphical resources.
    cleanup();

    // Tear down OpenGL.
    tearDownOpenGL();

    return isOk ? 0 : -1;
}
