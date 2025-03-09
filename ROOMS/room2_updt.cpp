extern float MouseX, MouseY;
extern float menustartbuttonxpos;
extern float mssbtxps;
extern float msextxps;
extern int mncsd;
extern double fpss;
extern bool bigmode;
extern int drtxmd;
extern float sddst1y;
extern float sddst1w;
extern int WindowH, WindowW;
void room2_updt()
{
	if (bigmode)
	{
		if (MouseY > 150*2 && MouseY < 188 * 2 && MouseX < 112 * 2) {
			mncsd = 4;
		}
		else {
			if (MouseY > 188 * 2 && MouseY < 226 * 2 && MouseX < 112 * 2) {
				mncsd = 5;
			}
			else {
				if (MouseY > 226 * 2 && MouseY < 264 * 2 && MouseX < 112 * 2) {
					mncsd = 6;
				}
				else if (MouseY > 400 * 2 && MouseY < 438 * 2 && MouseX < 112 * 2) {
					mncsd = 8;
				}
				else if (MouseY > (214 + 38 * 2 )* 2&& MouseY < (214 * 2 + 38 * 3 )* 2 && MouseX < 219 * 2) {
					mncsd = 9;
				}
				else {
					mncsd = 7;
				}
			}
		}
		if (mncsd == 4) {
			sddst1y += (138 - sddst1y) / fpss * 10;
			sddst1w += (112 - sddst1w) / fpss * 10;
		}
		else if (mncsd == 5) {
			sddst1y += (176 - sddst1y) / fpss * 10;
			sddst1w += (112 - sddst1w) / fpss * 10;
		}
		else if (mncsd == 6) {
			sddst1y += (214 - sddst1y) / fpss * 10;
			sddst1w += (112 - sddst1w) / fpss * 10;
		}
		else if (mncsd == 7 || mncsd == 8) {
			sddst1y += (138 + drtxmd * 38 - sddst1y) / fpss * 10;
			sddst1w += (112 - sddst1w) / fpss * 10;
		}
		else if (mncsd == 9) {
			sddst1y += (214 + 38 * 2 - sddst1y) / fpss * 10;
			sddst1w += (219 - sddst1w) / fpss * 10;
		}
		if (mncsd==8) {
			msextxps += (50 - msextxps) / fpss * 10;
		}
		else {
			msextxps += (0 - msextxps) / fpss * 10;
		}
	}
	else {
		if (MouseY > 150 && MouseY < 188 && MouseX < 112) {
			mncsd = 4;
		}
		else {
			if (MouseY > 188 && MouseY < 226 && MouseX < 112) {
				mncsd = 5;
			}
			else {
				if (MouseY > 226 && MouseY < 264 && MouseX < 112) {
					mncsd = 6;
				}
				else if (MouseY > 400 && MouseY < 438 && MouseX < 112) {
					mncsd = 8;
				}
				else if (MouseY > 214 + 38 * 2 && MouseY < 214 + 38 * 3 && MouseX < 219) {
					mncsd = 9;
				}
				else {
					mncsd = 7;
				}
			}
		}
		if (mncsd == 4) {
			sddst1y += (138 - sddst1y) / fpss * 10;
			sddst1w += (112 - sddst1w) / fpss * 10;
		}
		else if (mncsd == 5) {
			sddst1y += (176 - sddst1y) / fpss * 10;
			sddst1w += (112 - sddst1w) / fpss * 10;
		}
		else if (mncsd == 6) {
			sddst1y += (214 - sddst1y) / fpss * 10;
			sddst1w += (112 - sddst1w) / fpss * 10;
		}
		else if (mncsd == 7||mncsd==8) {
			sddst1y += (138 + drtxmd * 38 - sddst1y) / fpss * 10;
			sddst1w += (112 - sddst1w) / fpss * 10;
		}
		else if (mncsd == 9) {
			sddst1y += (214 + 38 * 2 - sddst1y) / fpss * 10;
			sddst1w += (219 - sddst1w) / fpss * 10;
		}
		if (MouseY > 400 && MouseY < 438 && MouseX < 112) {
			msextxps += (50 - msextxps) / fpss * 10;
		}
		else {
			msextxps += (0 - msextxps) / fpss * 10;
		}
	}
}