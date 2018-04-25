
layout (location = 0) in vec3 aPos;


uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;

void main()
{
    //  
    gl_Position = Projection* View*  vec4(aPos, 1.0); 
}



