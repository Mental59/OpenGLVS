#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <chrono>
#include "Matrix.h"
#include "Vector.h"

using namespace std;

GLFWwindow *g_window;
int screen_width = 800, screen_height = 600;

GLfloat lastX = screen_width / 2.0f, lastY = screen_height / 2.0f;
GLfloat yaw = -90.0f, pitch = 0.0f;
bool firstMouse = true;

GLuint g_shaderProgram;
GLint g_uM;
GLint g_uV;
GLint g_uP;
GLint g_uParams;

GLfloat params[] = { -0.05f, -90.0f, -5.0f };
int sign1 = 1;
int sign2 = 1;

Vector3 cameraPos = Vector3(0.0f, 0.0f, 3.0f);
Vector3 cameraFront = Vector3(0.0f, 0.0f, -1.0f);
Vector3 cameraUp = Vector3(0.0f, 1.0f, 0.0f);

bool keys[1024];

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

GLfloat to_radians(GLfloat degrees)
{
    return PI / 180.0f * degrees;
}

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
    "uniform mat4 u_m;"
    "uniform mat4 u_v;"
    "uniform mat4 u_p;"
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
    "   mat4 mv = u_v * u_m;"
    "   mat4 mvp = u_p * mv;"
    ""
    "   float y = f(a_position);"
    "   vec4 p0 = vec4(a_position[0], y, a_position[1], 1.0);"
    "   v_normal = transpose(inverse(mat3(mv))) * normalize(gradient(a_position));"
    "   v_pos = vec3(mv * p0);"
    "   gl_Position = mvp * p0;"
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
    "   vec3 color = vec3(0.19, 0.83, 0.78);"
    ""
    "   vec3 E = vec3(0.0, 0.0, 0.0);"
    "   vec3 L = vec3(5.0, 5.0, 0.0);"
    "   float S = 90.0;"
    ""
    "   vec3 n = normalize(v_normal);"
    "   vec3 l = normalize(L - v_pos);"
    ""
    "   float d = max(dot(n, l), 0.1);"
    ""
    "   vec3 e = normalize(-v_pos);"
    "   vec3 h = normalize(l + e);"
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

    g_uM = glGetUniformLocation(g_shaderProgram, "u_m");
    g_uV = glGetUniformLocation(g_shaderProgram, "u_v");
    g_uP = glGetUniformLocation(g_shaderProgram, "u_p");
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
    glClearColor(0.0f, 0.2f, 0.2f, 1.0f);

    glEnable(GL_DEPTH_TEST);

    return createShaderProgram() && createModel();
}

void reshape(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void draw(double delta)
{
    params[1] += delta * 12.0 * sign1;
    params[0] += delta * 0.005 * sign2;

    // Clear color buffer.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUseProgram(g_shaderProgram);
    glBindVertexArray(g_model.vao);

    static Matrix4 T = createTranslateMatrix(0.0f, 0.0f, 0.0f);

    static Matrix4 Rx = createRotateXMatrix(35.0f);

    static Matrix4 M = Rx; // Model matrix

    Matrix4 V = createLookAtMatrix(cameraPos, cameraPos + cameraFront, cameraUp); // View matrix

    static Matrix4 P = createPerspectiveProjectionMatrix(100.0f, 0.01f, 40.0f, 4, 3); // Projection matrix

    
    glUniformMatrix4fv(g_uM, 1, GL_FALSE, M.getTransposedElements());
    glUniformMatrix4fv(g_uV, 1, GL_FALSE, V.getTransposedElements());
    glUniformMatrix4fv(g_uP, 1, GL_FALSE, P.getTransposedElements());
    glUniform3fv(g_uParams, 1, params);

    glDrawElements(GL_TRIANGLES, g_model.indexCount, GL_UNSIGNED_INT, NULL);

    if (abs(params[1]) > 90.0)
        sign1 *= -1;
    if (params[0] > 0.0 || params[0] < -0.05)
        sign2 *= -1;
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
    g_window = glfwCreateWindow(screen_width, screen_height, "OpenGL Test", NULL, NULL);
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

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);

    if (action == GLFW_PRESS)
        keys[key] = true;
    else if (action == GLFW_RELEASE)
        keys[key] = false;
}

void do_movement(double deltaTime)
{
    // Camera controls
    GLfloat cameraSpeed = 3.0f * deltaTime;
    if (keys[GLFW_KEY_W])
        cameraPos = cameraPos + cameraSpeed * cameraFront;
    if (keys[GLFW_KEY_S])
        cameraPos = cameraPos - cameraSpeed * cameraFront;
    if (keys[GLFW_KEY_A])
        cameraPos = cameraPos - Vector3::normalize(Vector3::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (keys[GLFW_KEY_D])
        cameraPos = cameraPos + Vector3::normalize(Vector3::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (keys[GLFW_KEY_Q])
        cameraPos = cameraPos - cameraUp * cameraSpeed;
    if (keys[GLFW_KEY_E])
        cameraPos = cameraPos + cameraUp * cameraSpeed;
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    GLfloat xoffset = xpos - lastX;
    GLfloat yoffset = lastY - ypos; // Обратный порядок вычитания потому что оконные Y-координаты возрастают с верху вниз 
    lastX = xpos;
    lastY = ypos;

    GLfloat sensitivity = 0.075f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw += xoffset;
    pitch += yoffset;

    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;

    Vector3 front = Vector3(
        cos(to_radians(yaw)) * cos(to_radians(pitch)),
        sin(to_radians(pitch)),
        sin(to_radians(yaw)) * cos(to_radians(pitch))
    );

    cameraFront = Vector3::normalize(front);
}

int main()
{   
    // Initialize OpenGL
    if (!initOpenGL())
        return -1;

    // Initialize graphical resources.
    bool isOk = init();

    glfwSetKeyCallback(g_window, key_callback);
    glfwSetCursorPosCallback(g_window, mouse_callback);
    glfwSetInputMode(g_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    if (isOk)
    {
        g_callTime = chrono::system_clock::now();
        // Main loop until window closed or escape pressed.
        while (!glfwWindowShouldClose(g_window))
        {
            auto callTime = chrono::system_clock::now();
            chrono::duration<double> elapsed = callTime - g_callTime;
            g_callTime = callTime;

            double deltaTime = elapsed.count();

            // Poll window events.
            glfwPollEvents();

            do_movement(deltaTime);

            // Draw scene.
            draw(deltaTime);

            // Swap buffers.
            glfwSwapBuffers(g_window);
        }
    }

    // Cleanup graphical resources.
    cleanup();

    // Tear down OpenGL.
    tearDownOpenGL();

    return isOk ? 0 : -1;
}
