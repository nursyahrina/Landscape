/**************************
 * Includes
 *
 **************************/

#include <windows.h>
#include <gl/gl.h>


/**************************
 * Function Declarations
 *
 **************************/

LRESULT CALLBACK WndProc (HWND hWnd, UINT message,
WPARAM wParam, LPARAM lParam);
void EnableOpenGL (HWND hWnd, HDC *hDC, HGLRC *hRC);
void DisableOpenGL (HWND hWnd, HDC hDC, HGLRC hRC);


/**************************
 * WinMain
 *
 **************************/

int WINAPI WinMain (HINSTANCE hInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpCmdLine,
                    int iCmdShow)
{
    WNDCLASS wc;
    HWND hWnd;
    HDC hDC;
    HGLRC hRC;        
    MSG msg;
    BOOL bQuit = FALSE;
    float theta = 0.0f;

    /* register window class */
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor (NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH) GetStockObject (BLACK_BRUSH);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = "GLSample";
    RegisterClass (&wc);

    /* create main window */
    hWnd = CreateWindow (
      "GLSample", "OpenGL Sample", 
      WS_CAPTION | WS_POPUPWINDOW | WS_VISIBLE,
      0, 0, 256, 256,
      NULL, NULL, hInstance, NULL);

    /* enable OpenGL for the window */
    EnableOpenGL (hWnd, &hDC, &hRC);

    /* program main loop */
    while (!bQuit)
    {
        /* check for messages */
        if (PeekMessage (&msg, NULL, 0, 0, PM_REMOVE))
        {
            /* handle or dispatch messages */
            if (msg.message == WM_QUIT)
            {
                bQuit = TRUE;
            }
            else
            {
                TranslateMessage (&msg);
                DispatchMessage (&msg);
            }
        }
        else
        {
            /* OpenGL animation code goes here */

            glClearColor (0.788f, 0.945f, 1.0f, 0.0f);
            glClear (GL_COLOR_BUFFER_BIT);

            glPushMatrix ();
            //glRotatef (theta, 0.0f, 0.0f, 1.0f);
            
            /* Matahari */
             glBegin (GL_POLYGON);
			glColor3f (1.0f, 0.855f, 0.141f);    
				glVertex2f (-0.7f, 0.89f);
				glVertex2f (-0.66f, 0.76f);    
				glVertex2f (-0.75f, 0.66f);
            	glVertex2f (-0.88f, 0.7f);
				glVertex2f (-0.92f, 0.82f);
				glVertex2f (-0.83f, 0.92f);  
            glEnd ();
                      
            /* Pegunungan */
            glBegin (GL_POLYGON);
			glColor3f (0.510f, 0.859f, 0.114f);    
				glVertex2f (0.67f, 0.65f);
				glVertex2f (1.0f, 0.37f); 
			glColor3f (0.130f, 0.49f, 0.039f);   
				glVertex2f (1.0f, -0.28f);
            	glVertex2f (-1.0f, -0.28f);   
            glEnd ();
            
            glBegin (GL_TRIANGLES);
			glColor3f (0.510f, 0.859f, 0.114f);    
				glVertex2f (-1.0f, 0.4f);
			glColor3f (0.130f, 0.49f, 0.039f);   
				glVertex2f (0.0f, -0.28f);
            	glVertex2f (-1.0f, -0.28f);   
            glEnd ();
            
            glBegin (GL_TRIANGLES);
			glColor3f (0.510f, 0.859f, 0.114f);    
				glVertex2f (-0.29f, 0.86f);
			glColor3f (0.078f, 0.361f, 0.0f);    
				glVertex2f (0.4f, -0.28f);
            	glVertex2f (-1.0f, -0.28f);   
            glEnd ();
            
            /* Awan */
            glBegin (GL_POLYGON);
			glColor3f (0.98f, 0.98f, 0.98f);    
				glVertex2f (0.13f, 0.86f);
				glVertex2f (0.27f, 0.91f);
				glVertex2f (0.4f, 0.88f);
				glVertex2f (0.57f, 0.91f);
				glVertex2f (0.79f, 0.84f);
			glColor3f (0.91f, 0.91f, 0.91f);   
				glVertex2f (0.57f, 0.81f);
            	glVertex2f (0.45f, 0.82f); 
				glVertex2f (0.25f, 0.8f);   
            glEnd ();
            
            glBegin (GL_POLYGON);
			glColor3f (0.98f, 0.98f, 0.98f);    
				glVertex2f (-0.56f, 0.67f);
				glVertex2f (-0.36f, 0.76f);
				glVertex2f (-0.17f, 0.75f);
				glVertex2f (-0.02f, 0.68f);
				glVertex2f (0.15f, 0.7f);
				glVertex2f (0.33f, 0.64f);
			glColor3f (0.91f, 0.91f, 0.91f);   
				glVertex2f (0.11f, 0.57f);
            	glVertex2f (-0.12f, 0.62f); 
				glVertex2f (-0.3f, 0.59f);   
            glEnd ();
            
            /* Dataran */
            glBegin (GL_POLYGON);
			glColor3f (0.341f, 0.761f, 0.0f);
				glVertex2f (-1.0f, -0.28f);
				glVertex2f (0.55f, -0.1f);
				glVertex2f (1.0f, -0.1f);
			glColor3f (0.259f, 0.137f, 0.0f); 
				glVertex2f (1.0f, -0.5f);
            	glVertex2f (-1.0f, -0.5f);   
            glEnd ();
            
            /* Sungai */
            glBegin (GL_POLYGON);
			glColor3f (0.129f, 0.769f, 1.0f); 
				glVertex2f (-1.0f, -0.5f);
				glVertex2f (1.0f, -0.5f);
			glColor3f (0.0f, 0.471f, 0.588f);   
				glVertex2f (1.0f, -1.0f);
            	glVertex2f (-1.0f, -1.0f);   
            glEnd ();
            
            /* Perahu */
            glBegin (GL_POLYGON);
			glColor3f (0.055f, 0.18f, 0.6f); 
				glVertex2f (0.34f, -0.7f);
				glVertex2f (0.85f, -0.74f);
			glColor3f (0.055f, 0.141f, 0.42f);   
				glVertex2f (0.8f, -0.79f);
            	glVertex2f (0.38f, -0.79f);   
            glEnd ();
            
            glBegin (GL_TRIANGLES);
            glColor3f (1.0f, 0.2f, 0.255f);  
				glVertex2f (0.33f, -0.66f);
				glVertex2f (0.63f, -0.37f);
			glColor3f (0.53f, 0.012f, 0.047f);   
				glVertex2f (0.6f, -0.72f);  
            glEnd ();
            
            /* Riak Sungai */
            glBegin (GL_POLYGON);
			glColor3f (0.710f, 0.922f, 1.0f); 
				glVertex2f (-0.8f, -0.66f);
				glVertex2f (-0.52f, -0.67f);
			glColor3f (0.129f, 0.769f, 1.0f);   
				glVertex2f (-0.4f, -0.7f);
            	glVertex2f (-0.92f, -0.7f);   
            glEnd ();
            
            glBegin (GL_POLYGON);
			glColor3f (0.710f, 0.922f, 1.0f); 
				glVertex2f (-0.05f, -0.57f);
				glVertex2f (0.11f, -0.58f);
			glColor3f (0.129f, 0.769f, 1.0f);    
				glVertex2f (0.3f, -0.6f);
            	glVertex2f (-0.2f, -0.6f);   
            glEnd ();

			glBegin (GL_POLYGON);
			glColor3f (0.710f, 0.922f, 1.0f); 
				glVertex2f (-0.34f, -0.86f);
				glVertex2f (-0.13f, -0.87f);
			glColor3f (0.129f, 0.769f, 1.0f);   
				glVertex2f (0.02f, -0.91f);
            	glVertex2f (-0.5f, -0.9f);   
            glEnd ();
            
            glBegin (GL_POLYGON);
			glColor3f (0.710f, 0.922f, 1.0f); 
				glVertex2f (0.46f, -0.77);
				glVertex2f (0.66f, -0.77f);
			glColor3f (0.129f, 0.769f, 1.0f);    
				glVertex2f (0.85f, -0.8f);
            	glVertex2f (0.32f, -0.8f);   
            glEnd ();
            
            /* Tenda camp */
            glBegin (GL_TRIANGLES);
			glColor3f (0.839f, 0.337f, 0.0f);  
				glVertex2f (-0.58f, -0.15f);    
				glVertex2f (-0.46f, -0.32f);
            	glVertex2f (-0.69f, -0.34f);   
            glEnd ();
            
            glBegin (GL_TRIANGLES);
			glColor3f (0.0f, 0.0f, 0.0f);    
				glVertex2f (-0.58f, -0.15f);   
				glVertex2f (-0.54f, -0.32f);
            	glVertex2f (-0.62f, -0.33f);   
            glEnd ();
            
            glBegin (GL_POLYGON);
			glColor3f (0.957f, 0.855f, 0.192f);    
				glVertex2f (-0.72f, -0.16f);
            	glVertex2f (-0.58f, -0.15f);
            glColor3f (0.839f, 0.337f, 0.0f);
				glVertex2f (-0.69f, -0.34f);
            	glVertex2f (-0.81f, -0.29f);   
            glEnd ();
            
            /* Pohon */
            	// Daun Pohon (1-8 Kiri ke kanan)
            glBegin (GL_TRIANGLES);
			glColor3f (0.0f, 0.69f, 0.047f);    
				glVertex2f (-0.01f, 0.18f);
			glColor3f (0.0f, 0.29f, 0.02f);    
				glVertex2f (0.08f, -0.14f);
            	glVertex2f (-0.1f, -0.14f);   
            glEnd ();
            
            glBegin (GL_TRIANGLES);
			glColor3f (0.0f, 0.69f, 0.047f);    
				glVertex2f (0.12f, 0.11f);
			glColor3f (0.0f, 0.29f, 0.02f);    
				glVertex2f (0.18f, -0.2f);
            	glVertex2f (0.05f, -0.2f);   
            glEnd ();
            
            glBegin (GL_TRIANGLES);
			glColor3f (0.0f, 0.69f, 0.047f);    
				glVertex2f (0.23f, 0.22f);
			glColor3f (0.0f, 0.29f, 0.02f);    
				glVertex2f (0.3f, -0.1f);
            	glVertex2f (0.15f, -0.1f);   
            glEnd ();
            
            glBegin (GL_TRIANGLES);
			glColor3f (0.0f, 0.69f, 0.047f);    
				glVertex2f (0.36f, 0.3f);
			glColor3f (0.0f, 0.29f, 0.02f);    
				glVertex2f (0.45f, -0.06f);
            	glVertex2f (0.27f, -0.06f);   
            glEnd ();
            
            glBegin (GL_TRIANGLES);
			glColor3f (0.0f, 0.69f, 0.047f);    
				glVertex2f (0.51f, 0.36f);
			glColor3f (0.0f, 0.29f, 0.02f);    
				glVertex2f (0.58f, 0.0f);
            	glVertex2f (0.42f, 0.0f);   
            glEnd ();
            
            glBegin (GL_TRIANGLES);
			glColor3f (0.0f, 0.69f, 0.047f);    
				glVertex2f (0.62f, 0.34f);
			glColor3f (0.0f, 0.29f, 0.02f);    
				glVertex2f (0.7f, -0.05f);
            	glVertex2f (0.53f, -0.05f);   
            glEnd ();
            
            glBegin (GL_TRIANGLES);
			glColor3f (0.0f, 0.69f, 0.047f);    
				glVertex2f (0.76f, 0.3f);
			glColor3f (0.0f, 0.29f, 0.02f);    
				glVertex2f (0.83f, -0.08f);
            	glVertex2f (0.68f, -0.08f);   
            glEnd ();
			
			glBegin (GL_TRIANGLES);
			glColor3f (0.0f, 0.69f, 0.047f);   
				glVertex2f (0.87f, 0.37f);
			glColor3f (0.0f, 0.29f, 0.02f);    
				glVertex2f (0.93f, -0.03f);
            	glVertex2f (0.79f, -0.03f);   
            glEnd ();
			            
            	// Batang Pohon (1-8 Kiri ke kanan)
            glBegin (GL_POLYGON);
			glColor3f (0.259f, 0.137f, 0.0f);    
				glVertex2f (-0.04f, -0.14f);   
				glVertex2f (0.02f, -0.14f);
            	glVertex2f (0.02f, -0.27f);
				glVertex2f (-0.04f, -0.27f);   
            glEnd ();
            
            glBegin (GL_POLYGON);
			glColor3f (0.259f, 0.137f, 0.0f);    
				glVertex2f (0.09f, -0.2f);   
				glVertex2f (0.14f, -0.2f);
            	glVertex2f (0.14f, -0.31f);
				glVertex2f (0.09f, -0.31f);   
            glEnd ();
            
            glBegin (GL_POLYGON);
			glColor3f (0.259f, 0.137f, 0.0f);    
				glVertex2f (0.2f, -0.1f);   
				glVertex2f (0.25f, -0.1f);
            	glVertex2f (0.25f, -0.23f);
				glVertex2f (0.2f, -0.23f);   
            glEnd ();
            
            glBegin (GL_POLYGON);
			glColor3f (0.259f, 0.137f, 0.0f);    
				glVertex2f (0.33f, -0.06f);   
				glVertex2f (0.38f, -0.06f);
            	glVertex2f (0.38f, -0.18f);
				glVertex2f (0.33f, -0.18f);   
            glEnd ();
            
            glBegin (GL_POLYGON);
			glColor3f (0.259f, 0.137f, 0.0f);    
				glVertex2f (0.47f, 0.0f);   
				glVertex2f (0.52f, 0.0f);
            	glVertex2f (0.52f, -0.15f);
				glVertex2f (0.47f, -0.15f);   
            glEnd ();
            
            glBegin (GL_POLYGON);
			glColor3f (0.259f, 0.137f, 0.0f);    
				glVertex2f (0.59f, -0.05f);   
				glVertex2f (0.64f, -0.05f);
            	glVertex2f (0.64f, -0.19f);
				glVertex2f (0.59f, -0.19f);   
            glEnd ();
            
            glBegin (GL_POLYGON);
			glColor3f (0.259f, 0.137f, 0.0f);    
				glVertex2f (0.73f, -0.08f);   
				glVertex2f (0.78f, -0.08f);
            	glVertex2f (0.78f, -0.2f);
				glVertex2f (0.73f, -0.2f);   
            glEnd ();
            
            glBegin (GL_POLYGON);
			glColor3f (0.259f, 0.137f, 0.0f);    
				glVertex2f (0.84f, -0.03f);   
				glVertex2f (0.89f, -0.03f);
            	glVertex2f (0.89f, -0.16f);
				glVertex2f (0.84f, -0.16f);   
            glEnd ();
			            
            glPopMatrix ();

            SwapBuffers (hDC);

            theta += 1.0f;
            Sleep (1);
        }
    }

    /* shutdown OpenGL */
    DisableOpenGL (hWnd, hDC, hRC);

    /* destroy the window explicitly */
    DestroyWindow (hWnd);

    return msg.wParam;
}


/********************
 * Window Procedure
 *
 ********************/

LRESULT CALLBACK WndProc (HWND hWnd, UINT message,
                          WPARAM wParam, LPARAM lParam)
{

    switch (message)
    {
    case WM_CREATE:
        return 0;
    case WM_CLOSE:
        PostQuitMessage (0);
        return 0;

    case WM_DESTROY:
        return 0;

    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_ESCAPE:
            PostQuitMessage(0);
            return 0;
        }
        return 0;

    default:
        return DefWindowProc (hWnd, message, wParam, lParam);
    }
}


/*******************
 * Enable OpenGL
 *
 *******************/

void EnableOpenGL (HWND hWnd, HDC *hDC, HGLRC *hRC)
{
    PIXELFORMATDESCRIPTOR pfd;
    int iFormat;

    /* get the device context (DC) */
    *hDC = GetDC (hWnd);

    /* set the pixel format for the DC */
    ZeroMemory (&pfd, sizeof (pfd));
    pfd.nSize = sizeof (pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | 
      PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;
    iFormat = ChoosePixelFormat (*hDC, &pfd);
    SetPixelFormat (*hDC, iFormat, &pfd);

    /* create and enable the render context (RC) */
    *hRC = wglCreateContext( *hDC );
    wglMakeCurrent( *hDC, *hRC );

}


/******************
 * Disable OpenGL
 *
 ******************/

void DisableOpenGL (HWND hWnd, HDC hDC, HGLRC hRC)
{
    wglMakeCurrent (NULL, NULL);
    wglDeleteContext (hRC);
    ReleaseDC (hWnd, hDC);
}
