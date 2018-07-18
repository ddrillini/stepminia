// included from main_loop.cpp

// blinking
receptor_time = receptor_clock.getElapsedTime();
if ( receptor_time >= sf::milliseconds(1000) )
{
	receptor_clock.restart();

	// rotate the queue
	receptor_texture_queue.push(receptor_temp_texture);
	receptor_temp_texture = receptor_texture_queue.front();
	receptor_texture_queue.pop();

	receptor_texture_0.swap(receptor_temp_texture);
}

