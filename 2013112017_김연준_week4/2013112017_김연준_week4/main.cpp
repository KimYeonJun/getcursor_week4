#include <GLFW/glfw3.h>
#include <cstring>
#include <stdlib.h>        // srand, rand
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <time.h>
#include "math.h"

const int width = 1200;
const int height = 500;

float* pixels = new float[width*height * 3];

void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	pixels[(i + width* j) * 3 + 0] = red;
	pixels[(i + width* j) * 3 + 1] = green;
	pixels[(i + width* j) * 3 + 2] = blue;
}

void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	if (i0 == i1)
	{
		for (int j = j0; j < j1; j++)
		{
			drawPixel(i0, j, red, green, blue);
		}
		return;
	}
	for (int i = i0; i <= i1; i++)
	{

		const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

		drawPixel(i, j, red, green, blue);
	}
}
void drawThickLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{

	for (int i = i0; i <= i1; i++)
	{

		const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

		drawPixel(i, j - 1, red, green, blue);
		drawPixel(i, j, red, green, blue);
		drawPixel(i, j + 1, red, green, blue);
	}
}
//void drawCircle(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
void drawCircle(const int& i0, const int& j0, const int& r, const float& red, const float& green, const float& blue)
{

	for (int i = i0 - r; i <= i0 + r; i++)
	{
		for (int j = j0 - r; j <= j0 + r; j++)
		{
			int f = (i - i0)*(i - i0) + (j - j0)*(j - j0) - r*r;

			int f1 = (i - i0)*(i - i0) + (j - j0)*(j - j0) - (r - 3)*(r - 3);
			if (f <= 0 && f1 >= 0)
			{

				drawPixel(i, j, red, blue, green);

			}

		}
	}


}
void drawIcon(const int& i0, const int& j0, const int& r, const float& red, const float& green, const float& blue, GLFWwindow* window)
{
	double xpos, ypos;

	for (int i = i0 - r; i <= i0 + r; i++)
	{
		for (int j = j0 - r; j <= j0 + r; j++)
		{
			glfwGetCursorPos(window, &xpos, &ypos);
			ypos = height - ypos - 1;
			int f = (i - i0)*(i - i0) + (j - j0)*(j - j0) - r*r;
			int f2 = (xpos - i0)*(xpos - i0) + (ypos - j0)*(ypos - j0) - r*r;
			int f1 = (i - i0)*(i - i0) + (j - j0)*(j - j0) - (r - 3)*(r - 3);
			if (f2 <= 0)
			{
				if (f <= 0 && f1 >= 0)
				{
					drawPixel(i, j, red, green, blue);
				}
			}


		}
	}


}
void drawSmallCircle(const int& i0, const int& j0, const int& r, const float& red, const float& green, const float& blue)
{

	for (int i = i0 - r; i <= i0 + r; i++)
	{
		for (int j = j0 - r; j <= j0 + r; j++)
		{
			int f = (i - i0)*(i - i0) + (j - j0)*(j - j0) - r*r;

			int f1 = (i - i0)*(i - i0) + (j - j0)*(j - j0) - (r - 10)*(r - 10);
			if (f <= 0 && f1 >= 0)
			{

				drawPixel(i, j, red, blue, green);

			}

		}
	}


}
void drawOnPixelBuffer(GLFWwindow* window)
{
	//std::memset(pixels, 1.0f, sizeof(float)*width*height * 3); // doesn't work
	std::fill_n(pixels, width*height * 3, 1.0f);   // white background

												   //for (int i = 0; i<width*height; i++) {
												   //   pixels[i * 3 + 0] = 1.0f; // red 
												   //   pixels[i * 3 + 1] = 1.0f; // green
												   //   pixels[i * 3 + 2] = 1.0f; // blue
												   //}

	const int i = rand() % width, j = rand() % height;
	/*drawPixel(i, j, 0.0f, 0.0f, 0.0f);*/

	// drawing a line
	//TODO: anti-aliasing
	const int i0 = 100, i1 = 200;
	const int j0 = 50, j1 = 50;

	//drawThickLine(80, 300, 150, 400, 0.0f, 0.0f, 0.0f);//drawThickLine

	//drawLine(220, 300, 380, 300, 0.0f, 0.0f, 0.0f); //draw Square
	//drawLine(380, 300, 380, 450, 0.0f, 0.0f, 0.0f);
	//drawLine(220, 450, 380, 450, 0.0f, 0.0f, 0.0f);
	//drawLine(220, 300, 220, 450, 0.0f, 0.0f, 0.0f);

	//for (int k = 300;k <= 450;k++)  //draw Square(filled with a non-white color)
	//{
	//   drawLine(420, k, 600, k, 0.0f, 0.0f, 0.0f);
	//}

	////drawLine(70, 150, 150, 150, 0.0f, 0.0f, 0.0f); //draw Triangle
	////drawLine(110, 190, 150, 150, 0.0f, 0.0f, 0.0f);
	////drawLine(70, 150, 110, 190, 0.0f, 0.0f, 0.0f);
	//drawLine(70, 50, 150, 50, 0.0f, 0.0f, 0.0f); //draw Triangle
	//drawLine(110, 190, 150, 50, 0.0f, 0.0f, 0.0f);
	//drawLine(70, 50, 110, 190, 0.0f, 0.0f, 0.0f);
	//drawLine(70, 51, 110, 191, 0.0f, 0.0f, 0.0f);

	//drawLine(300, 200, 400, 150, 0.0f, 0.0f, 0.0f);//draw pentagon
	//drawLine(350, 100, 400, 150, 0.0f, 0.0f, 0.0f);
	//drawLine(250, 100, 350, 100, 0.0f, 0.0f, 0.0f);
	//drawLine(200, 150, 250, 100, 0.0f, 0.0f, 0.0f);
	//drawLine(200, 150, 300, 200, 0.0f, 0.0f, 0.0f);


	drawCircle(120, 120, 100, 1.0f, 0.0f, 0.0f);
	drawIcon(120, 120, 100, 0.0f, 0.0f, 1.0f, window);
	drawLine(150, 80, 180, 120, 1.0f, 0.0f, 0.0f);
	drawLine(150, 79, 180, 119, 1.0f, 0.0f, 0.0f);
	drawLine(150, 160, 180, 120, 1.0f, 0.0f, 0.0f);
	drawLine(150, 161, 180, 120, 1.0f, 0.0f, 0.0f);
	drawLine(60, 120, 180, 120, 1.0f, 0.0f, 0.0f);


	drawCircle(360, 120, 100, 1.0f, 0.0f, 0.0f);
	drawIcon(360, 120, 100, 0.0f, 0.0f, 1.0f, window);
	drawThickLine(290, 80, 360, 180, 1.0f, 0.0f, 0.0f);
	drawThickLine(360, 180, 430, 80, 1.0f, 0.0f, 0.0f);
	drawLine(322, 125, 398, 125, 1.0f, 0.0f, 0.0f);


	drawCircle(600, 120, 100, 1.0f, 0.0f, 0.0f);
	drawIcon(600, 120, 100, 0.0f, 0.0f, 1.0f, window);
	drawLine(600, 50, 600, 180, 1.0f, 0.0f, 0.0f);



	drawCircle(840, 120, 100, 1.0f, 0.0f, 0.0f);
	drawIcon(840, 120, 100, 0.0f, 0.0f, 1.0f, window);
	drawThickLine(780, 120, 810, 80, 1.0f, 0.0f, 0.0f);
	drawThickLine(780, 120, 810, 160, 1.0f, 0.0f, 0.0f);
	drawLine(780, 120, 880, 120, 1.0f, 0.0f, 0.0f);

	drawCircle(1080, 120, 100, 1.0f, 0.0f, 0.0f);
	drawIcon(1080, 120, 100, 0.0f, 0.0f, 1.0f, window);
	drawLine(1050, 150, 1080, 180, 1.0f, 0.0f, 0.0f);
	drawLine(1080, 180, 1110, 150, 1.0f, 0.0f, 0.0f);
	drawLine(1080, 50, 1080, 180, 1.0f, 0.0f, 0.0f);

	drawCircle(120, 360, 100, 1.0f, 0.0f, 0.0f);
	drawIcon(120, 360, 100, 0.0f, 0.0f, 1.0f, window);
	drawThickLine(80, 320, 160, 400, 1.0f, 0.0f, 0.0f);

	drawCircle(360, 360, 100, 1.0f, 0.0f, 0.0f);
	drawIcon(360, 360, 100, 0.0f, 0.0f, 1.0f, window);
	drawSmallCircle(360, 360, 30, 1.0f, 0.0f, 0.0f);

	drawCircle(600, 360, 100, 1.0f, 0.0f, 0.0f);
	drawIcon(600, 360, 100, 0.0f, 0.0f, 1.0f, window);
	drawLine(575, 335, 625, 335, 1.0f, 0.0f, 0.0f);
	drawLine(625, 335, 625, 385, 1.0f, 0.0f, 0.0f);
	drawLine(575, 385, 625, 385, 1.0f, 0.0f, 0.0f);
	drawLine(575, 335, 575, 385, 1.0f, 0.0f, 0.0f);

	drawCircle(840, 360, 100, 1.0f, 0.0f, 0.0f);
	drawIcon(840, 360, 100, 0.0f, 0.0f, 1.0f, window);
	drawLine(790, 300, 890, 420, 1.0f, 0.0f, 0.0f);
	drawLine(790, 420, 890, 300, 1.0f, 0.0f, 0.0f);

	drawCircle(1080, 360, 100, 1.0f, 0.0f, 0.0f);
	drawIcon(1080, 360, 100, 0.0f, 0.0f, 1.0f, window);
	drawLine(1080, 300, 1080, 400, 1.0f, 0.0f, 0.0f);
	drawLine(1050, 320, 1080, 300, 1.0f, 0.0f, 0.0f);
	drawLine(1080, 300, 1110, 320, 1.0f, 0.0f, 0.0f);

	//TODO: try moving object

}

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "getcursor", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glClearColor(1, 1, 1, 1); // while background

							  /* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		//glClear(GL_COLOR_BUFFER_BIT);

		drawOnPixelBuffer(window);

		//TODO: RGB struct
		//Make a pixel drawing function
		//Make a line drawing function

		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	glfwTerminate();

	delete[] pixels; // or you may reuse pixels array 

	return 0;
}
