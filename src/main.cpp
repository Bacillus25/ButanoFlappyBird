#include "bn_core.h"
#include "bn_math.h"
#include "bn_random.h"
#include "bn_keypad.h"
#include "bn_display.h"
#include "bn_blending.h"
#include "bn_bg_palettes.h"

#include "bn_sprite_text_generator.h"

#include "bn_sprite_first_attributes_hbe_ptr.h"
#include "bn_sprite_third_attributes_hbe_ptr.h"
#include "bn_sprite_affine_second_attributes.h"
#include "bn_sprite_regular_second_attributes.h"
#include "bn_sprite_affine_second_attributes_hbe_ptr.h"
#include "bn_sprite_regular_second_attributes_hbe_ptr.h"

#include "bn_sprite_items_blue_sprite.h"
#include "bn_sprite_items_bird.h"
#include "bn_sprite_items_pipe.h"
#include "bn_sprite_items_pipedown.h"
#include "Player.h"
#include "Pipe.h"
#include "variable_8x16_sprite_font.h"

#include "bn_string.h"

bn::fixed velocity = 0;
bn::fixed gravity = 0.5;
bn::vector<Pipe, 4> pipes;

int timer = 0;
int timer_max_time = 80;
bn::random random;

int score = 0;

bool isAlive = true;

Pipe randomPipe()
{
    bn::sprite_ptr pipeSpriteTop = bn::sprite_items::pipedown.create_sprite(0, 0);
    bn::sprite_ptr pipeSpriteBottom = bn::sprite_items::pipe.create_sprite(0, 0);


    int randomInt = random.get_int(-20, 20);
    Pipe random_pipe(pipeSpriteTop,pipeSpriteBottom , 150, randomInt);
    return random_pipe;
}

int main()
{
    bn::core::init();
    bn::bg_palettes::set_transparent_color(bn::color(16, 24, 31)); // Sky blue
    bn::sprite_ptr bird = bn::sprite_items::bird.create_sprite(-30, 0);

    bn::sprite_text_generator text_generator(common::variable_8x16_sprite_font);
    bn::vector<bn::sprite_ptr, 32> text_sprites;
    // text_generator.generate(0, -50, bn::to_string<32>(score), text_sprites);
    




    Player player(bird);
    

    while (isAlive)
    {
        timer -= 1;
        if (timer <= 0)
        {
            Pipe pipe = randomPipe();
            if (pipes.size() > pipes.max_size() -1)
            {
                pipes.erase(pipes.begin());
            }
            pipes.push_back(pipe);
            timer = timer_max_time;
        }

        // if (player.position().y() > 80 or player.position().y() < -50){
        //     isAlive = false;
        // }


        text_sprites.clear();

        // text_generator.generate(0, -50, bn::to_string<32>(score), text_sprites);

        for (Pipe& i : pipes)
        {
            i.update();
            // if (i.get_collision_rect_top().intersects(player.get_collision_rect()) || i.get_collision_rect_bottom().intersects(player.get_collision_rect()))
            // {
            //     isAlive = false;
            // }
            // if (i.get_collision_rect_score().intersects(player.get_collision_rect()) && i.get_is_enabled()){
            //     score += 1;
                

            //     i.set_is_enabled(false);
            // };

        }
        player.update();
        bn::core::update();

        
    }
    
}

