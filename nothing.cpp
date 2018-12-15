//1. Create Game Window .. OK

#include <stdio.h>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

const int W = 640;
const int H = 480;

int main(void)
{
	RenderWindow window(VideoMode(W, H,32), "mandelbrot");
	Image        image;image.create(W, H);
	Texture t;
	Sprite s;

	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed) window.close();
		}
		window.clear();

		for (int y = 0; y < H; y++)for (int x = 0; x < W; x++)
		{
			const int max_iter = 1000;
			double minx = -2.5, maxx = 1;
			double miny = -1, maxy = 1;
			double cr = minx + 1.0*(maxx - minx)*x / W;
			double ci = miny + 1.0*(maxy - miny)*y / H;
			double r = 0, i = 0;
			if (x == W / 2 && y == H / 2)
			{
				int sdf = 1;
			}
			int iter;
			for(iter=0;iter<max_iter;iter++)
			{
				double tr = r * r - i * i + cr;
				i = 2 * r*i + ci;
				r = tr;
				if (r*r + i * i > 2 * 2) break;
			}

			int rr = 1.0*(max_iter-iter) / max_iter * 0xff;
			int gg = rr, bb = rr;
			int color = (rr << 24) | (gg << 16) | (bb<<8)|(0xff);
			image.setPixel(x, y, Color(color));

		}

		t.loadFromImage(image);
		s.setTexture(t);
		window.draw(s);



		window.display();
	}

	return 0;
}