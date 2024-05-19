#include <GL/glew.h>

// este macro pone un breakpoint en el código si la condición no se cumple
#define ASSERT(x) if (!(x)) __debugbreak(); //__debugbreak() varia dependiendo del compilador

// este macro limpia los errores previos de OpenGL y luego ejecuta la función x, si hay errores imprime un mensaje
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))


// esta función limpia los errores de OpenGL
static void GLClearError()
{
    while (glGetError() != GL_NO_ERROR);
}

// esta función imprime los errores de OpenGL
static bool GLLogCall(const char* function, const char* file, int line)
{
    while (GLenum error = glGetError())
    {
        std::cout << "[OpenGL Error] (" << error << "): " << function << " " << file << ":" << line << std::endl;
        return false;
    }
    return true;
}