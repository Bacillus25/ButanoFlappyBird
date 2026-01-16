#ifndef player_h
#define player_h

#include "bn_sprite_ptr.h"
#include "bn_fixed.h"
#include "bn_optional.h"
#include "bn_fixed_rect.h"

class Player
{
private:
    bn::sprite_ptr _sprite;
    bn::fixed _velocity_y;
    bn::fixed_rect _collisionSquare;

    static constexpr bn::fixed GRAVITY = 0.6;
    static constexpr bn::fixed JUMP_FORCE = -7;
    static constexpr bn::fixed MAX_FALL_SPEED = 5;

public:
    Player(bn::sprite_ptr sprite);
    
    void update();

    bn::fixed_point position() const;

    void set_position(bn::fixed x, bn::fixed y);

    bn::fixed_rect get_collision_rect();
};

#endif