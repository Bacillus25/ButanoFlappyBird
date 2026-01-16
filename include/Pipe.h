#ifndef pipe_h
#define pipe_h

#include "bn_sprite_ptr.h"
#include "bn_fixed.h"
#include "bn_optional.h"
#include "bn_fixed_rect.h"

class Pipe
{
private:
    bn::sprite_ptr _sprite_top;
    bn::sprite_ptr _sprite_bottom;
    bn::fixed_rect _collisionRectTop;
    bn::fixed_rect _collisionRectBottom;
    bn::fixed_rect _collisionRectScore;


    bn::fixed _x_pos;
    bn::fixed _y_pos;
    bool _is_enabled;

public:
    Pipe(bn::sprite_ptr sprite_top,bn::sprite_ptr _sprite_bottom, bn::fixed x_pos, bn::fixed y_pos);

    void update();

    bn::fixed_rect get_collision_rect_top();
    bn::fixed_rect get_collision_rect_bottom();
    bn::fixed_rect get_collision_rect_score();
    void disable_score_collider();
    bool get_is_enabled();
    void set_is_enabled(bool status);
};

#endif