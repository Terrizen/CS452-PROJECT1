#include "initShaders.h"
#include <cstdlib>
using namespace std;

void rotate(GLuint locate);

GLuint 	vaoID, vboID[2], eboID,
	vaoID2, vboID2[2], eboID2,
	vaoID3, vboID3[2], eboID3,
	vaoID4, vboID4[2], eboID4,
	vaoID5, vboID5[2], eboID5,
	vaoID6, vboID6[2], eboID6,
	vaoID7, vboID7[2], eboID7;
GLuint program;

GLfloat pit,yaw,scalar=1;
glm::vec3 cubeTran, cubeTran2, cubeTran3, cubeTran4, cubeTran5, cubeTran6, cubeTran7;

GLfloat vertexarray[]={-14.0f, 1.0f, 0.0f,
                       -13.0f, 1.0f, 0.0f,
                       -13.0f, 0.0f, 0.0f,
                       -14.0f, 0.0f, 0.0f
                       };

GLfloat vertexarray2[]={-100.0f, 3.0f, -0.0f,
                       100.0f, 3.0f, -0.0f,
                       100.0f, 28.0f, -0.0f,
                       -100.0f, 28.0f, -0.0f
                       };

GLfloat vertexarray3[]={10.0f, 3.0f, -0.0f,
                       25.0f, 3.0f, -0.0f,
                       25.0f, -50.0f, -0.0f,
                       10.0f, -50.0f, -0.0f
                       };

GLfloat vertexarray4[]={-100.0f, -21.0f, -0.0f,
                       100.0f, -21.0f, -0.0f,
                       100.0f, -50.0f, -0.0f,
                       -100.0f, -50.0f, -0.0f
                       };
GLfloat vertexarray5[]={-15.0f, 3.0f, -0.0f,
                       -30.0f, 3.0f, -0.0f,
                       -30.0f, -50.0f, -0.0f,
                       -15.0f, -50.0f, -0.0f
                       };

GLfloat vertexarray6[]={-15.0f, -1.0f, -0.0f,
                       6.0f, -1.0f, -0.0f,
                       6.0f, -17.0f, -0.0f,
                       -15.0f, -17.0f, -0.0f
                       };

GLfloat vertexarray7[]={-15.0f, -17.0f, -0.0f,
                       -13.0f, -17.0f, -0.0f,
                       -13.0f, -21.0f, -0.0f,
                       -15.0f, -21.0f, -0.0f
                       };


GLfloat colorarray[]={0.9f,0.6f,0.4f,1.0f,
           	      0.5f,0.2f,0.6f,1.0f,
                      0.7f,0.4f,0.2f,1.0f,
                      0.6f,0.3f,0.5f,1.0f
                                        };

GLfloat colorarray2[]={0.0f,1.0f,0.0f,1.0f,
                      0.0f,1.0f,0.0f,1.0f,
                      0.0f,1.0f,0.0f,1.0f,
                      0.0f,1.0f,0.0f,1.0f
                                        };


 GLubyte elems[]={0,1,2,3,7,4,5,6,
                  7,3,0,4,5,6,2,1,
                  0,1,5,4,7,3,2,6
                 };

void init(){
         glEnable(GL_DEPTH_TEST);
         glViewport(0, 0, 600, 600);

        glGenVertexArrays(1,&vaoID);
        glBindVertexArray(vaoID);

        glGenBuffers(2, vboID);
        glBindBuffer(GL_ARRAY_BUFFER,vboID[0]);
        glBufferData(GL_ARRAY_BUFFER,sizeof(vertexarray),vertexarray,GL_STATIC_DRAW);
        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);

	glBindBuffer(GL_ARRAY_BUFFER, vboID[1]);
        glBufferData(GL_ARRAY_BUFFER,sizeof(colorarray),colorarray,GL_STATIC_DRAW);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1,&eboID);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,eboID);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(elems),elems,GL_STATIC_DRAW);
  
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	
	glGenVertexArrays(1,&vaoID2);
        glBindVertexArray(vaoID2);

        glGenBuffers(2, vboID2);
        glBindBuffer(GL_ARRAY_BUFFER,vboID2[0]);
        glBufferData(GL_ARRAY_BUFFER,sizeof(vertexarray2),vertexarray2,GL_STATIC_DRAW);
        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);

        glBindBuffer(GL_ARRAY_BUFFER, vboID2[1]);
        glBufferData(GL_ARRAY_BUFFER,sizeof(colorarray2),colorarray2,GL_STATIC_DRAW);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

        glGenBuffers(1,&eboID2);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,eboID2);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(elems),elems,GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        glGenVertexArrays(1,&vaoID3);
        glBindVertexArray(vaoID3);

        glGenBuffers(2, vboID3);
        glBindBuffer(GL_ARRAY_BUFFER,vboID3[0]);
        glBufferData(GL_ARRAY_BUFFER,sizeof(vertexarray3),vertexarray3,GL_STATIC_DRAW);
        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);

        glBindBuffer(GL_ARRAY_BUFFER, vboID3[1]);
        glBufferData(GL_ARRAY_BUFFER,sizeof(colorarray2),colorarray2,GL_STATIC_DRAW);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

        glGenBuffers(1,&eboID3);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,eboID3);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(elems),elems,GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        glGenVertexArrays(1,&vaoID4);
        glBindVertexArray(vaoID4);

        glGenBuffers(2, vboID4);
        glBindBuffer(GL_ARRAY_BUFFER,vboID4[0]);
        glBufferData(GL_ARRAY_BUFFER,sizeof(vertexarray4),vertexarray4,GL_STATIC_DRAW);
        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);

        glBindBuffer(GL_ARRAY_BUFFER, vboID4[1]);
        glBufferData(GL_ARRAY_BUFFER,sizeof(colorarray2),colorarray2,GL_STATIC_DRAW);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

        glGenBuffers(1,&eboID4);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,eboID4);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(elems),elems,GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        glGenVertexArrays(1,&vaoID5);
        glBindVertexArray(vaoID5);

        glGenBuffers(2, vboID5);
        glBindBuffer(GL_ARRAY_BUFFER,vboID5[0]);
        glBufferData(GL_ARRAY_BUFFER,sizeof(vertexarray5),vertexarray5,GL_STATIC_DRAW);
        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);

        glBindBuffer(GL_ARRAY_BUFFER, vboID5[1]);
        glBufferData(GL_ARRAY_BUFFER,sizeof(colorarray2),colorarray2,GL_STATIC_DRAW);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

        glGenBuffers(1,&eboID5);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,eboID5);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(elems),elems,GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        glGenVertexArrays(1,&vaoID6);
        glBindVertexArray(vaoID6);

        glGenBuffers(2, vboID6);
        glBindBuffer(GL_ARRAY_BUFFER,vboID6[0]);
        glBufferData(GL_ARRAY_BUFFER,sizeof(vertexarray6),vertexarray6,GL_STATIC_DRAW);
        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);

        glBindBuffer(GL_ARRAY_BUFFER, vboID6[1]);
        glBufferData(GL_ARRAY_BUFFER,sizeof(colorarray2),colorarray2,GL_STATIC_DRAW);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

        glGenBuffers(1,&eboID6);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,eboID6);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(elems),elems,GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        glGenVertexArrays(1,&vaoID7);
        glBindVertexArray(vaoID7);

        glGenBuffers(2, vboID7);
        glBindBuffer(GL_ARRAY_BUFFER,vboID7[0]);
        glBufferData(GL_ARRAY_BUFFER,sizeof(vertexarray7),vertexarray7,GL_STATIC_DRAW);
        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);

        glBindBuffer(GL_ARRAY_BUFFER, vboID7[1]);
        glBufferData(GL_ARRAY_BUFFER,sizeof(colorarray),colorarray,GL_STATIC_DRAW);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

        glGenBuffers(1,&eboID7);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,eboID7);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(elems),elems,GL_STATIC_DRAW);

        ShaderInfo shaders[]={
  { GL_VERTEX_SHADER , "vertexshader.glsl"},
  { GL_FRAGMENT_SHADER , "fragmentshader.glsl"},
  { GL_NONE , NULL}
  };

  program=initShaders(shaders);

  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);


}




void display(SDL_Window* screen){
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

        glm::mat4 trans,trans2,trans3,trans4, trans5, trans6, trans7;

	// draw first object
        trans=glm::translate(trans,cubeTran);

  	GLint tempLoc = glGetUniformLocation(program,"modelMatrix");
        glUniformMatrix4fv(tempLoc,1,GL_FALSE,&trans[0][0]);

	glBindVertexArray(vaoID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboID);
        glDrawElements(GL_POLYGON,4,GL_UNSIGNED_BYTE,NULL);

	//draw third object
	trans3=glm::translate(trans3,cubeTran3);

        tempLoc = glGetUniformLocation(program,"modelMatrix");
        glUniformMatrix4fv(tempLoc,1,GL_FALSE,&trans3[0][0]);

        glBindVertexArray(vaoID3);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboID3);
        glDrawElements(GL_POLYGON,4,GL_UNSIGNED_BYTE,NULL);

	//draw forth object
        trans4=glm::translate(trans4,cubeTran4);

        tempLoc = glGetUniformLocation(program,"modelMatrix");
        glUniformMatrix4fv(tempLoc,1,GL_FALSE,&trans4[0][0]);

        glBindVertexArray(vaoID4);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboID4);
        glDrawElements(GL_POLYGON,4,GL_UNSIGNED_BYTE,NULL);

	//draw fifth object
        trans5=glm::translate(trans5,cubeTran5);

        tempLoc = glGetUniformLocation(program,"modelMatrix");
        glUniformMatrix4fv(tempLoc,1,GL_FALSE,&trans5[0][0]);

        glBindVertexArray(vaoID5);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboID5);
        glDrawElements(GL_POLYGON,4,GL_UNSIGNED_BYTE,NULL);

	//draw sixth object
        trans6=glm::translate(trans6,cubeTran6);

        tempLoc = glGetUniformLocation(program,"modelMatrix");
        glUniformMatrix4fv(tempLoc,1,GL_FALSE,&trans6[0][0]);

        glBindVertexArray(vaoID6);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboID6);
        glDrawElements(GL_POLYGON,4,GL_UNSIGNED_BYTE,NULL);

	//draw seventh object
        trans7=glm::translate(trans7,cubeTran7);

        tempLoc = glGetUniformLocation(program,"modelMatrix");
        glUniformMatrix4fv(tempLoc,1,GL_FALSE,&trans7[0][0]);

        glBindVertexArray(vaoID7);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboID7);
        glDrawElements(GL_POLYGON,4,GL_UNSIGNED_BYTE,NULL);

	// draw second object
        trans2=glm::translate(trans2,cubeTran2);

  	tempLoc = glGetUniformLocation(program,"modelMatrix");
        glUniformMatrix4fv(tempLoc,1,GL_FALSE,&trans2[0][0]);

	glBindVertexArray(vaoID2);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboID2);
        glDrawElements(GL_POLYGON,4,GL_UNSIGNED_BYTE,NULL);
        glFlush();
        SDL_GL_SwapWindow(screen);
}

void input(SDL_Window* screen){

SDL_Event event;
	float w = cubeTran.y;
	float z = cubeTran.x;
	int counter = 0;
        while (SDL_PollEvent(&event)){
		if( counter == 1)
			{
				cout<<  "Congrats, You Won!!! \n";
				exit(0);
				break;
			}
                switch (event.type){
                        case SDL_QUIT:exit(0);break;
                        case SDL_KEYDOWN:
                                switch(event.key.keysym.sym){
                                        case SDLK_ESCAPE:exit(0);
                                        case SDLK_w:cubeTran.y+=2;break;
                                        case SDLK_s:cubeTran.y-=2;break;
                                        case SDLK_a:cubeTran.x-=2;break;
                                        case SDLK_d:cubeTran.x+=2;break;
				}
			if(((cubeTran.y <= -1.0 && cubeTran.y >= -17.0) || cubeTran.y >= 3.0) && cubeTran.x <= 19.0 && cubeTran.x >= -1.0)
				{	
					cubeTran.y = 0;
					cubeTran.x = 0;
				}
			else if((cubeTran.x <= 21.0 || cubeTran.y >= 24.0) && cubeTran.x <= -1.0 && cubeTran.x >= -17.0)
                                {
                                        cubeTran.y = 0;
                                        cubeTran.x = 0;
                                }
			else if(cubeTran.y >= 3.0)
				{
					cubeTran.y = 0;
                                        cubeTran.x = 0;
				}
			else if(cubeTran.x >= 24.0)
                                {
                                        cubeTran.y = 0;
                                        cubeTran.x = 0;
                                }
			else if(cubeTran.y <= -21.0)
                                {
                                        cubeTran.y = 0;
                                        cubeTran.x = 0;
                                }
			else if(cubeTran.x <= -1.0)
                                {
                                        cubeTran.y = 0;
                                        cubeTran.x = 0;
                                }
			else if(cubeTran.x <= 1.0  && cubeTran.y <= -17.0)
				{
					counter++;
					break;
				} 


                }
        }
}


int main(int argc, char **argv){

        SDL_Window *window;

        if(SDL_Init(SDL_INIT_VIDEO)<0){
                fprintf(stderr,"Unable to create window: %s\n", SDL_GetError());
    SDL_Quit();
    exit(1);
        }

        window = SDL_CreateWindow(
                "Happy Days",
                SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED,
                500,
                500,
                SDL_WINDOW_OPENGL
        );

        if(window==NULL){
                fprintf(stderr,"Unable to create window: %s\n",SDL_GetError());
        }


        SDL_GLContext glcontext=SDL_GL_CreateContext(window);

  glewExperimental=GL_TRUE;
  if(glewInit()){
    fprintf(stderr, "Unable to initalize GLEW");
    exit(EXIT_FAILURE);
  }

        init();

        while(true){
          input(window);
                display(window);
        }

        SDL_GL_DeleteContext(glcontext);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}

