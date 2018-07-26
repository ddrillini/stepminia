// included by main_loop.cpp

// = Clear screen ===========================================================
window.clear();

// = Draw from screenstate vector ===========================================
for ( auto &sprite : screenstate->sprite_draw_vector )
	window.draw(*sprite);

// = Update the window ======================================================
window.display();
