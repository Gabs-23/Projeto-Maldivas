#include "rendering.h"
#include "constants.h"
#include "collision.h"
#include <stdio.h>


static bool button_pressed = false;

void render_game(GameState estado, Resources* res, Player* player, Projectile* projectiles, int num_projectiles,
    Rect continuar_botao, Rect sair_botao, int mouse_x, int mouse_y, Rect start_button, Rect prologo_button, Rect credits_button, Rect Instructs_button) {
    if (estado == MENU) {
        // Desenha a imagem do menu ou limpa a tela
        if (res->menu_image) {
            al_draw_bitmap(res->menu_image, 0, 0, 0);
        }
        else {
            al_clear_to_color(al_map_rgb(0, 0, 0));
        }

        // Bot�o "Start": Verifica se o mouse est� sobre o bot�o
        ALLEGRO_COLOR cor_start = al_map_rgb(100, 100, 100); // Cor padr�o
        if (mouse_x >= start_button.x1 && mouse_x <= start_button.x2 &&
            mouse_y >= start_button.y1 && mouse_y <= start_button.y2) {
            cor_start = al_map_rgb(150, 150, 150); // Cor quando o mouse est� sobre o bot�o
        }

        // Desenha o bot�o "Start"
        al_draw_filled_rectangle(
            start_button.x1, start_button.y1,
            start_button.x2, start_button.y2,
            cor_start
        );
        al_draw_rectangle(
            start_button.x1, start_button.y1,
            start_button.x2, start_button.y2,
            al_map_rgb(255, 255, 255), 2
        );

        // Desenha o texto "Start" no bot�o
        if (res->font) {
            const char* texto_start = "Start";
            int largura_texto = al_get_text_width(res->font, texto_start);
            int altura_texto = al_get_font_line_height(res->font);
            al_draw_text(res->font, al_map_rgb(255, 255, 255),
                (start_button.x1 + start_button.x2 - largura_texto) / 2,
                (start_button.y1 + start_button.y2 - altura_texto) / 2,
                ALLEGRO_ALIGN_LEFT, texto_start);
        }

        // Bot�o "Creditos": Verifica se o mouse est� sobre o bot�o
        ALLEGRO_COLOR cor_credits = al_map_rgb(100, 100, 100); // Cor padr�o
        if (mouse_x >= credits_button.x1 && mouse_x <= credits_button.x2 &&
            mouse_y >= credits_button.y1 && mouse_y <= credits_button.y2) {
            cor_credits = al_map_rgb(150, 150, 150); // Cor quando o mouse est� sobre o bot�o
        }

        // Desenha o bot�o "Creditos"
        al_draw_filled_rectangle(
            credits_button.x1, credits_button.y1,
            credits_button.x2, credits_button.y2,
            cor_credits
        );
        al_draw_rectangle(
            credits_button.x1, credits_button.y1,
            credits_button.x2, credits_button.y2,
            al_map_rgb(255, 255, 255), 2
        );

        // Desenha o texto "Creditos" no bot�o
        if (res->font) {
            const char* texto_credits = "Credits";
            int largura_texto = al_get_text_width(res->font, texto_credits);
            int altura_texto = al_get_font_line_height(res->font);
            al_draw_text(res->font, al_map_rgb(255, 255, 255),
                (credits_button.x1 + credits_button.x2 - largura_texto) / 2,
                (credits_button.y1 + credits_button.y2 - altura_texto) / 2,
                ALLEGRO_ALIGN_LEFT, texto_credits);
        }

        // Bot�o "Instru��es": Verifica se o mouse est� sobre o bot�o
        ALLEGRO_COLOR cor_instructs = al_map_rgb(100, 100, 100); // Cor padr�o
        if (mouse_x >= Instructs_button.x1 && mouse_x <= Instructs_button.x2 &&
            mouse_y >= Instructs_button.y1 && mouse_y <= Instructs_button.y2) {
            cor_instructs = al_map_rgb(150, 150, 150); // Cor quando o mouse est� sobre o bot�o
        }

        // Desenha o bot�o "Instru��es"
        al_draw_filled_rectangle(
            Instructs_button.x1, Instructs_button.y1,
            Instructs_button.x2, Instructs_button.y2,
            cor_instructs
        );
        al_draw_rectangle(
            Instructs_button.x1, Instructs_button.y1,
            Instructs_button.x2, Instructs_button.y2,
            al_map_rgb(255, 255, 255), 2
        );

        // Desenha o texto "Instru��es" no bot�o
        if (res->font) {
            const char* texto_intructions = "Instruction";
            int largura_texto = al_get_text_width(res->font, texto_intructions);
            int altura_texto = al_get_font_line_height(res->font);
            al_draw_text(res->font, al_map_rgb(255, 255, 255),
                (Instructs_button.x1 + Instructs_button.x2 - largura_texto) / 2,
                (Instructs_button.y1 + Instructs_button.y2 - altura_texto) / 2,
                ALLEGRO_ALIGN_LEFT, texto_intructions);
        }

        al_flip_display();  // Atualiza a tela
    }

    //PROLOGO COM INTRODU��O 
    else if (estado == PROLOGO) {
        al_clear_to_color(COR_FUNDO);
        al_draw_bitmap(res->bg_prologo, 0 , 0, 0);

        // Bot�o "Prologo": Verifica se o mouse est� sobre o bot�o
        ALLEGRO_COLOR cor_prologo = al_map_rgb(100, 100, 100); // Cor padr�o
        if (mouse_x >= prologo_button.x1 && mouse_x <= prologo_button.x2 &&
            mouse_y >= prologo_button.y1 && mouse_y <= prologo_button.y2) {
            cor_prologo = al_map_rgb(150, 150, 150); // Cor quando o mouse est� sobre o bot�o
        }

        // Desenha o bot�o "Prologo"
        al_draw_filled_rectangle(
            prologo_button.x1, prologo_button.y1,
            prologo_button.x2, prologo_button.y2,
            cor_prologo
        );
        al_draw_rectangle(
            prologo_button.x1, prologo_button.y1,
            prologo_button.x2, prologo_button.y2,
            al_map_rgb(255, 255, 255), 2
        );

        // Desenha o texto "Continua" no bot�o
        if (res->font) {
            const char* texto_prologo = "Continuar";
            int largura_texto = al_get_text_width(res->font, texto_prologo);
            int altura_texto = al_get_font_line_height(res->font);
            al_draw_text(res->font, al_map_rgb(255, 255, 255),
                (prologo_button.x1 + prologo_button.x2 - largura_texto) / 2,
                (prologo_button.y1 + prologo_button.y2 - altura_texto) / 2,
                ALLEGRO_ALIGN_LEFT, texto_prologo);
        }

        al_flip_display();
    }
    // PROLOGO COM COM DIALOGO ENTRE NPCS
    else if (estado == PROLOGO2) {
        al_clear_to_color(COR_GAME_OVER);
        al_draw_bitmap(res->bg_prologo2, 195, 0, 0);
        //carrega npc chefe
      
        al_draw_bitmap_region(res->NPC_CHEFE, 0, 104, 34, 52, 445, 475, 0);
        //ADD NPC 
        al_draw_bitmap_region(res->NPC_ENGENHEIRO, 0, 52, 34, 52, 500, 475, 0);

        // Bot�o "Prologo": Verifica se o mouse est� sobre o bot�o
        ALLEGRO_COLOR cor_prologo = al_map_rgb(100, 100, 100); // Cor padr�o
        if (mouse_x >= prologo_button.x1 && mouse_x <= prologo_button.x2 &&
            mouse_y >= prologo_button.y1 && mouse_y <= prologo_button.y2) {
            cor_prologo = al_map_rgb(150, 150, 150); // Cor quando o mouse est� sobre o bot�o
        }

        // Desenha o bot�o "Prologo"
        al_draw_filled_rectangle(
            prologo_button.x1, prologo_button.y1,
            prologo_button.x2, prologo_button.y2,
            cor_prologo
        );
        al_draw_rectangle(
            prologo_button.x1, prologo_button.y1,
            prologo_button.x2, prologo_button.y2,
            al_map_rgb(255, 255, 255), 2
        );

        // Desenha o texto "Continua" no bot�o
        if (res->font) {
            const char* texto_prologo = "Continuar";
            int largura_texto = al_get_text_width(res->font, texto_prologo);
            int altura_texto = al_get_font_line_height(res->font);
            al_draw_text(res->font, al_map_rgb(255, 255, 255),
                (prologo_button.x1 + prologo_button.x2 - largura_texto) / 2,
                (prologo_button.y1 + prologo_button.y2 - altura_texto) / 2,
                ALLEGRO_ALIGN_LEFT, texto_prologo);
        }

        al_flip_display();
    }
    else if (estado == PROLOGO3) {
        al_clear_to_color(COR_FUNDO);
        al_draw_bitmap(res->bg_prologo3, 0, 0, 0);

        // Bot�o "Prologo": Verifica se o mouse est� sobre o bot�o
        ALLEGRO_COLOR cor_prologo = al_map_rgb(100, 100, 100); // Cor padr�o
        if (mouse_x >= prologo_button.x1 && mouse_x <= prologo_button.x2 &&
            mouse_y >= prologo_button.y1 && mouse_y <= prologo_button.y2) {
            cor_prologo = al_map_rgb(150, 150, 150); // Cor quando o mouse est� sobre o bot�o
        }

        // Desenha o bot�o "Prologo"
        al_draw_filled_rectangle(
            prologo_button.x1, prologo_button.y1,
            prologo_button.x2, prologo_button.y2,
            cor_prologo
        );
        al_draw_rectangle(
            prologo_button.x1, prologo_button.y1,
            prologo_button.x2, prologo_button.y2,
            al_map_rgb(255, 255, 255), 2
        );

        // Desenha o texto "Continua" no bot�o
        if (res->font) {
            const char* texto_prologo = "Continuar";
            int largura_texto = al_get_text_width(res->font, texto_prologo);
            int altura_texto = al_get_font_line_height(res->font);
            al_draw_text(res->font, al_map_rgb(255, 255, 255),
                (prologo_button.x1 + prologo_button.x2 - largura_texto) / 2,
                (prologo_button.y1 + prologo_button.y2 - altura_texto) / 2,
                ALLEGRO_ALIGN_LEFT, texto_prologo);
        }

        al_flip_display();
    }
    else if (estado == PROLOGO4) {
        al_clear_to_color(COR_FUNDO);
        al_draw_bitmap(res->bg_prologo4, 0, 0, 0);

        // Bot�o "Prologo": Verifica se o mouse est� sobre o bot�o
        ALLEGRO_COLOR cor_prologo = al_map_rgb(100, 100, 100); // Cor padr�o
        if (mouse_x >= prologo_button.x1 && mouse_x <= prologo_button.x2 &&
            mouse_y >= prologo_button.y1 && mouse_y <= prologo_button.y2) {
            cor_prologo = al_map_rgb(150, 150, 150); // Cor quando o mouse est� sobre o bot�o
        }

        // Desenha o bot�o "Prologo"
        al_draw_filled_rectangle(
            prologo_button.x1, prologo_button.y1,
            prologo_button.x2, prologo_button.y2,
            cor_prologo
        );
        al_draw_rectangle(
            prologo_button.x1, prologo_button.y1,
            prologo_button.x2, prologo_button.y2,
            al_map_rgb(255, 255, 255), 2
        );

        // Desenha o texto "Continua" no bot�o
        if (res->font) {
            const char* texto_prologo = "Continuar";
            int largura_texto = al_get_text_width(res->font, texto_prologo);
            int altura_texto = al_get_font_line_height(res->font);
            al_draw_text(res->font, al_map_rgb(255, 255, 255),
                (prologo_button.x1 + prologo_button.x2 - largura_texto) / 2,
                (prologo_button.y1 + prologo_button.y2 - altura_texto) / 2,
                ALLEGRO_ALIGN_LEFT, texto_prologo);
        }

        al_flip_display();
    }

    else if (estado == FASE_1) {
        al_clear_to_color(COR_FUNDO);
        al_draw_bitmap(res->BG_1, 0, 0, 0);

        Retangulos retangulo[] = {
            {0,0,260,320},
            {0,340,100,485},
            {180,380,260,485},
            {820,380,900,485},
            {980,330,1260,485},
            {820,0,1260,320},
            {500,210,580,385},
            {402,164,654,20},
            {580,320,660,370},
            {500,320,420,370},
            {444,433,470,508},
            {821,654,982,692},
            {97,655,255,688}
        };
/*
        for (int i = 0; i < sizeof(retangulo) / sizeof(Retangulos); i++) {
            ALLEGRO_COLOR cor = al_map_rgb(255, 0, 0);
            if (colisaoPersonagem(player, &retangulo[i])) {
                fprintf(stdout, "Colidiu com o ret�ngulo %d!\n", i);
            }
            // Desenhar o ret�ngulo
            al_draw_filled_rectangle(retangulo[i].x1, retangulo[i].y1,
                retangulo[i].x2, retangulo[i].y2, cor);
        }
        */
        // Desenha todos os proj�teis ativos
        for (int i = 0; i < num_projectiles; ++i) {
            if (projectiles[i].active) {
                draw_projectile(&projectiles[i]);
            }
        }

        // Desenha o jogador
        draw_player(player);

        // Desenha a barra de vida
        draw_life_bar(player);

        al_flip_display();
    }
    else if (estado == GAME_OVER) {
        // Desenha a tela de Game Over
        al_clear_to_color(COR_GAME_OVER); // Fundo preto

        if (res->font) {
            // Desenha "GAME OVER" no centro superior
            const char* texto_game_over = "GAME OVER";
            int largura_texto = al_get_text_width(res->font, texto_game_over);
            al_draw_text(res->font, al_map_rgb(255, 0, 0), (SCREEN_WIDTH - largura_texto) / 2, 200, ALLEGRO_ALIGN_LEFT, texto_game_over);
        }

        // Bot�o Continuar: Verifica se o mouse est� sobre o bot�o
        ALLEGRO_COLOR cor_continuar = al_map_rgb(100, 100, 100); // Cor padr�o
        if (mouse_x >= continuar_botao.x1 && mouse_x <= continuar_botao.x2 &&
            mouse_y >= continuar_botao.y1 && mouse_y <= continuar_botao.y2) {
            cor_continuar = al_map_rgb(150, 150, 150); // Cor hover
        }

        // Bot�o Sair: Verifica se o mouse est� sobre o bot�o
        ALLEGRO_COLOR cor_sair = al_map_rgb(100, 100, 100); // Cor padr�o
        if (mouse_x >= sair_botao.x1 && mouse_x <= sair_botao.x2 &&
            mouse_y >= sair_botao.y1 && mouse_y <= sair_botao.y2) {
            cor_sair = al_map_rgb(150, 150, 150); // Cor hover
        }

        // Bot�o Continuar
        al_draw_filled_rectangle(
            continuar_botao.x1, continuar_botao.y1,
            continuar_botao.x2, continuar_botao.y2,
            cor_continuar // Cor ajustada
        );
        al_draw_rectangle(
            continuar_botao.x1, continuar_botao.y1,
            continuar_botao.x2, continuar_botao.y2,
            al_map_rgb(255, 255, 255), 2 // Borda branca
        );

        if (res->font) {
            const char* texto_continuar = "Continuar";
            int largura_botao = al_get_text_width(res->font, texto_continuar);
            int altura_botao = al_get_font_line_height(res->font);
            al_draw_text(res->font, al_map_rgb(255, 255, 255),
                (continuar_botao.x1 + continuar_botao.x2 - largura_botao) / 2,
                (continuar_botao.y1 + continuar_botao.y2 - altura_botao) / 2,
                ALLEGRO_ALIGN_LEFT, texto_continuar);
        }

        // Bot�o Sair
        al_draw_filled_rectangle(
            sair_botao.x1, sair_botao.y1,
            sair_botao.x2, sair_botao.y2,
            cor_sair // Cor ajustada
        );
        al_draw_rectangle(
            sair_botao.x1, sair_botao.y1,
            sair_botao.x2, sair_botao.y2,
            al_map_rgb(255, 255, 255), 2 // Borda branca
        );

        if (res->font) {
            const char* texto_sair = "Sair";
            int largura_botao = al_get_text_width(res->font, texto_sair);
            int altura_botao = al_get_font_line_height(res->font);
            al_draw_text(res->font, al_map_rgb(255, 255, 255),
                (sair_botao.x1 + sair_botao.x2 - largura_botao) / 2,
                (sair_botao.y1 + sair_botao.y2 - altura_botao) / 2,
                ALLEGRO_ALIGN_LEFT, texto_sair);
        }

        al_flip_display();
    }
    else if (estado == CREDITOS) {
        // Desenha a tela de cr�ditos
        if (res->creditos) {
            al_draw_bitmap(res->creditos, 0, 0, 0);
        }
        al_flip_display();
    }
    else if (estado == INSTRU��ES) {
        // Desenha a tela de instru��es
        if (res->instructs) {
            al_draw_bitmap(res->instructs, 0, 0, 0);
        }
        al_flip_display();
    }
    else {
        // Caso nenhum dos estados anteriores seja correspondido, limpa a tela
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_flip_display();
    }
}