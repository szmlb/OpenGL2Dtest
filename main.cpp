#define GLFW_DLL

#define _USE_MATH_DEFINES


#include <GL/glfw.h>
#include <cstdlib>

#include <cmath>

#if defined (_MSC_VER)
#pragma comment(lib, "GLFWDLL.lib")
#pragma comment(lib, "opengl32.lib")
#endif

int main(){

	if (!glfwInit()){
		return EXIT_FAILURE;
	}

	if (!glfwOpenWindow(0, 0,
		0, 0, 0,
		0,
		0, 0,
		GLFW_WINDOW)){
		glfwTerminate();
		return EXIT_FAILURE;
	}

	glfwSwapInterval(1);
	while (glfwGetWindowParam(GLFW_OPENED)) {

		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		GLfloat vtx[20 * 2];
		for (int i = 0; i < 20; ++i){
			GLfloat angle = static_cast<GLfloat>((M_PI * 2.0 * i) / 20);
			vtx[i * 2] = std::sin(angle) * 0.5f;
			vtx[i * 2 + 1] = std::cos(angle) * 0.6f;
		}

		glVertexPointer(2, GL_FLOAT, 0, vtx);
		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
		
		glEnableClientState(GL_VERTEX_ARRAY);
		
		//glDrawArrays(GL_POINTS, 0, 1);
		//glDrawArrays(GL_LINES, 0, 2);
		glDrawArrays(GL_TRIANGLE_FAN, 0, 20);
		glDisableClientState(GL_VERTEX_ARRAY);

		glfwSwapBuffers();
	}
	glfwTerminate();

	return EXIT_SUCCESS;
}