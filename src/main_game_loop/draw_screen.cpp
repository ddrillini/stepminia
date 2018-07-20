// included by main_loop.cpp

// Clear screen
window.clear();


// = Receptor shrinking on keypress =========================================
// for each key's clock
for (int i=0; i < key_clock_vector.size(); i++)
{
	// getElapsedTime
	sf::Time t = key_clock_vector[i].getElapsedTime();

	// if it's been less than .2 seconds, scale
	if ( t < sf::seconds(.1) )
		scale_receptor(t, receptor_vector[i]);
}
// ==========================================================================


// = Draw receptors =========================================================
int i = 0;
for ( auto &sprite : receptor_vector )
	window.draw(sprite);
// ==========================================================================

// = Draw from screenstate vector ===========================================
for ( auto &sprite : playfield1.sprite_vector )
	window.draw(sprite);

// Update the window
window.display();
