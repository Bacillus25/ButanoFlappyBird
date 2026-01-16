#include "bn_core.h"
#include "player.h"
#include "bn_keypad.h"


Player::Player(bn::sprite_ptr sprite):
    _sprite(sprite),
    _velocity_y(0)
  {
    _sprite.set_y(0);
    _collisionSquare.set_dimensions(12, 12);
  }



void Player::update()
{
  if (_velocity_y < MAX_FALL_SPEED)
  {
    _velocity_y += GRAVITY;
  }
  
  if(bn::keypad::a_pressed())
  {
    _velocity_y = JUMP_FORCE;
  }
  
   _sprite.set_y(_sprite.y() + _velocity_y);
   _collisionSquare.set_position(position());
}

bn::fixed_point Player::position() const {
    return _sprite.position();
}

void Player::set_position(bn::fixed x, bn::fixed y) {
    _sprite.set_position(x, y);
}

bn:: fixed_rect Player::get_collision_rect(){
  return _collisionSquare;
}