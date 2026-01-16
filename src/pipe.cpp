#include "bn_core.h"
#include "pipe.h"
#include "bn_keypad.h"

Pipe::Pipe(bn::sprite_ptr sprite_top, bn::sprite_ptr sprite_bottom, bn::fixed x_pos, bn::fixed y_pos):
_sprite_top(sprite_top),
_sprite_bottom(sprite_bottom)
{
    _x_pos = x_pos;
    _y_pos = y_pos;

    _sprite_top.set_position(x_pos, y_pos - 68);
    _sprite_bottom.set_position(x_pos, y_pos + 68);

    _collisionRectTop.set_dimensions(32, 64);
    _collisionRectTop.set_position(_sprite_top.position());

    _collisionRectBottom.set_dimensions(32, 64);
    _collisionRectBottom.set_position(_sprite_bottom.position());

    _collisionRectScore.set_dimensions(20, 200);
    _collisionRectScore.set_position(x_pos, y_pos);

    _is_enabled = true;

}

void Pipe::update()
{
    _sprite_bottom.set_x(_sprite_bottom.x() - 2);
    _sprite_top.set_x(_sprite_bottom.x() - 2);

    _collisionRectTop.set_position(_sprite_top.position());
    _collisionRectBottom.set_position(_sprite_bottom.position());

    _collisionRectScore.set_x(_sprite_bottom.position().x());

}

bn:: fixed_rect Pipe::get_collision_rect_top(){
    return _collisionRectTop;
}

bn:: fixed_rect Pipe::get_collision_rect_bottom(){
    return _collisionRectBottom;
}

bn:: fixed_rect Pipe::get_collision_rect_score(){
    return _collisionRectScore;
}

void Pipe::disable_score_collider(){
    _collisionRectScore.set_dimensions(0, 0);
}

bool Pipe::get_is_enabled(){
    return _is_enabled;
}

void Pipe::set_is_enabled(bool status){
    _is_enabled = status;
}