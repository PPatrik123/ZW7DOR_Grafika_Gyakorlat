#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"
#include <SDL2/SDL.h>
#include <obj/model.h>

typedef struct Scene
{
    Model car;
    Model house;
    Model lightbulb;
    Model leftheadlight;
    Model rightheadlight;
    float headlight1_x;
    float headlight1_y;
    float headlight1_z;
    float headlight2_x;
    float headlight2_y;
    float headlight2_z;
    Model hood;
    Model hood1;
    Model hood2;
    Model hood3;
    Model hood4;
    Model hood5;
    Model hood6;
    Model hood7;
    Model leftdoor1;
    Model leftdoor2;
    Model leftdoor3;
    Model leftdoor4;
    Model leftdoor5;
    Model leftdoor6;
    Model leftdoor7;
    Model leftdoor8;
    Model rightdoor1;
    Model rightdoor2;
    Model rightdoor3;
    Model rightdoor4;
    Model rightdoor5;
    Model rightdoor6;
    Model rightdoor7;
    Model rightdoor8;
    Material material;
    GLuint texture_id;
    GLuint house_texture_id;
    int rightdoor_direction;
    int leftdoor_direction;
    int hood_direction;
    float light;
    int current_hood;
    int current_leftdoor;
    int current_rightdoor;
    Uint32 last_update;
} Scene;

/**
 * Initialize the scene by loading models and setting initial positions.
 */
void init_scene(Scene* scene);

/**
 * Set the lighting of the scene.
 */
void set_lighting(const Scene* scene)
;

/**
 * Set the current material.
 */
void set_material(const Material* material);

/**
 * Update the scene.
 */
void update_scene(Scene* scene);

/**
 * Render the scene objects.
 */
void render_scene(const Scene* scene);

void set_sun_brightness_inc(Scene* scene, float b);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

void rotate_hood(Scene* scene, float angle);

#endif /* SCENE_H */
