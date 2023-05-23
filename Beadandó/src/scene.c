#include "scene.h"

#include <obj/load.h>
#include <obj/draw.h>
#include <unistd.h>

void init_scene(Scene* scene)
{
    load_model(&(scene->house),"assets/models/double_garage.obj");
    scene->house_texture_id = load_texture("assets/textures/double garage2020.jpg");
    load_model(&(scene->car), "assets/models/newnissan.obj");
    load_model(&(scene->lightbulb),"assets/models/low poly lamp.obj");
    load_model(&(scene->rightheadlight),"assets/models/rightheadlight.obj");
    load_model(&(scene->leftheadlight),"assets/models/leftheadlight.obj");
    load_model(&(scene->rightdoor1),"assets/models/rightdoor.obj");
    load_model(&(scene->rightdoor2),"assets/models/rightdoor1.obj");
    load_model(&(scene->rightdoor3),"assets/models/rightdoor2.obj");
    load_model(&(scene->rightdoor4),"assets/models/rightdoor3.obj");
    load_model(&(scene->rightdoor5),"assets/models/rightdoor4.obj");
    load_model(&(scene->rightdoor6),"assets/models/rightdoor5.obj");
    load_model(&(scene->rightdoor7),"assets/models/rightdoor6.obj");
    load_model(&(scene->rightdoor8),"assets/models/rightdoor7.obj");
    load_model(&(scene->leftdoor1),"assets/models/leftdoor.obj");
    load_model(&(scene->leftdoor2),"assets/models/leftdoor1.obj");
    load_model(&(scene->leftdoor3),"assets/models/leftdoor2.obj");
    load_model(&(scene->leftdoor4),"assets/models/leftdoor3.obj");
    load_model(&(scene->leftdoor5),"assets/models/leftdoor4.obj");
    load_model(&(scene->leftdoor6),"assets/models/leftdoor5.obj");
    load_model(&(scene->leftdoor7),"assets/models/leftdoor6.obj");
    load_model(&(scene->leftdoor8),"assets/models/leftdoor7.obj");
    load_model(&(scene->hood),"assets/models/hood.obj");
    load_model(&(scene->hood1),"assets/models/hood2.obj");
    load_model(&(scene->hood2),"assets/models/hood3.obj");
    load_model(&(scene->hood3),"assets/models/hood4.obj");
    load_model(&(scene->hood4),"assets/models/hood5.obj");
    load_model(&(scene->hood5),"assets/models/hood6.obj");
    load_model(&(scene->hood6),"assets/models/hood7.obj");
    load_model(&(scene->hood7),"assets/models/hood8.obj");
    scene->texture_id = load_texture("assets/textures/Nissan2.jpg");
    scene->current_hood = 1;
    scene->current_leftdoor =1;
    scene->current_rightdoor = 1;
    
    scene->rightdoor_direction = 1;
    scene->leftdoor_direction = 1;
    scene->hood_direction = 1;
    scene->last_update = SDL_GetTicks();
    glBindTexture(GL_TEXTURE_2D, scene->texture_id);
    glEnable(GL_TEXTURE_2D); 
    
    
    scene->material.ambient.red = 0.5;
    scene->material.ambient.green = 0.5;
    scene->material.ambient.blue = 0.5;

    scene->material.diffuse.red = 1.0;
    scene->material.diffuse.green = 1.0;
    scene->material.diffuse.blue = 1.0; 

    scene->material.specular.red = 0.0;
    scene->material.specular.green = 0.0;
    scene->material.specular.blue = 0.0;

    scene->material.shininess = 0.0;
}

void set_lighting(const Scene* scene)
{
    float b = 0;
    b = scene->light / 255 ;
    float ambient_light[] = { b, b, b, 1.0f };
    float diffuse_light[] = { b, b, b, 1.0f };
    float specular_light[] = { b, b, b, 1.0f };
    float position[] = { 0.0f, 0.0f, 10.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void set_material(const Material* material)
{
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue
    };

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue
    };

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}

void update_scene(Scene* scene)
{

    Uint32 now = SDL_GetTicks();

   
    if (now - scene->last_update >= 3000)
    {
    
        if(scene->rightdoor_direction == 1){
            scene->current_rightdoor += 1;
            if (scene->current_rightdoor >= 8){
                scene->rightdoor_direction = -1;
            }
        } else {
            scene->current_rightdoor -= 1;
            if (scene->current_rightdoor <= 1){
                scene->rightdoor_direction = 1;
            }
        }

        if(scene->leftdoor_direction == 1){
            scene->current_leftdoor += 1;
            if (scene->current_leftdoor >= 8){
                scene->leftdoor_direction = -1;
            }
        } else {
            scene->current_leftdoor -= 1;
            if (scene->current_leftdoor <= 1){
                scene->leftdoor_direction = 1;
            }
        }

        if(scene->hood_direction == 1){
            scene->current_hood += 1;
            if (scene->current_hood >= 8){
                scene->hood_direction = -1;
            }
        } else {
            scene->current_hood -= 1;
            if (scene->current_hood <= 1){
                scene->hood_direction = 1;
            }
        }

        
        scene->last_update = now;
    }
}




void render_scene(const Scene* scene)
{
    
    set_material(&(scene->material));
    set_lighting(scene);
    glEnable(GL_TEXTURE_2D); 
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    //glScalef(0.7f, 0.7, 0.7f);
    draw_origin();
    glBindTexture(GL_TEXTURE_2D, scene->house_texture_id);
    glEnable(GL_TEXTURE_2D);
    draw_model(&(scene->house));
    glBindTexture(GL_TEXTURE_2D, scene->texture_id);
    draw_model(&(scene->car));


    float lightbulb_x = 0.0f;
    float lightbulb_y = 0.5f;
    float lightbulb_z = 0.0f;
    glPushMatrix();
    glTranslatef(lightbulb_x, lightbulb_y, lightbulb_z);
    draw_model(&(scene->lightbulb));
    glPopMatrix();

    draw_model(&(scene->rightheadlight));
    draw_model(&(scene->leftheadlight));
    

    switch (scene->current_rightdoor)
    {
    case 1:
        draw_model(&(scene->rightdoor1));
        break;
    case 2:
        draw_model(&(scene->rightdoor2));
        break;
    case 3:
        draw_model(&(scene->rightdoor3));
        break;
    case 4:
        draw_model(&(scene->rightdoor4));
        break;
    case 5:
        draw_model(&(scene->rightdoor5));
        break;
    case 6:
        draw_model(&(scene->rightdoor6));
        break;
    case 7:
        draw_model(&(scene->rightdoor7));
        break;
    case 8:
        draw_model(&(scene->rightdoor8));
        break;
    }

    switch (scene->current_leftdoor)
    {
    case 1:
        draw_model(&(scene->leftdoor1));
        break;
    case 2:
        draw_model(&(scene->leftdoor2));
        break;
    case 3:
        draw_model(&(scene->leftdoor3));
        break;
    case 4:
        draw_model(&(scene->leftdoor4));
        break;
    case 5:
        draw_model(&(scene->leftdoor5));
        break;
    case 6:
        draw_model(&(scene->leftdoor6));
        break;
    case 7:
        draw_model(&(scene->leftdoor7));
        break;
    case 8:
        draw_model(&(scene->leftdoor8));
        break;

    }

    switch (scene->current_hood) {
        case 1:
            draw_model(&(scene->hood));
            break;
        case 2:
            draw_model(&(scene->hood1));
            break;
        case 3:
            draw_model(&(scene->hood2));
            break;
        case 4:
            draw_model(&(scene->hood3));
            break;
        case 5:
            draw_model(&(scene->hood4));
            break;
        case 6:
            draw_model(&(scene->hood5));
            break;
        case 7:
            draw_model(&(scene->hood6));
            break;
        case 8:
            draw_model(&(scene->hood7));
            break;
    }
}


void draw_origin()
{
    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);

    glEnd();
}

void set_sun_brightness_inc(Scene* scene, float b)
{
   scene->light += b;

    if(scene->light > 255.0){
        scene->light = 255.0;
    }
    if(scene->light < 0.0){
        scene->light = 0.0;
    }
}
