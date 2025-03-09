extern float MouseX, MouseY;
extern float menustartbuttonxpos;
extern float mssbtxps;
extern float msextxps;
extern int mncsd;
extern double fpss;
extern bool bigmode;
void room1_updt() {
	if (bigmode)
	{
		if (MouseY > 150*2 && MouseY < 188*2 && MouseX < 112*2) {
			menustartbuttonxpos += (50 - menustartbuttonxpos) / fpss * 10;
		}
		else {
			menustartbuttonxpos += (0 - menustartbuttonxpos) / fpss * 10;

		}
		if (MouseY > 188*2 && MouseY < 226*2 && MouseX < 112*2) {
			mssbtxps += (50 - mssbtxps) / fpss * 10;
		}
		else {
			mssbtxps += (0 - mssbtxps) / fpss * 10;

		}
		if (MouseY > 226*2 && MouseY < 264*2 && MouseX < 112*2) {
			msextxps += (50 - msextxps) / fpss * 10;
		}
		else {
			msextxps += (0 - msextxps) / fpss * 10;
		}
		if (MouseY > 150*2 && MouseY < 188*2 && MouseX < 112*2) {
			mncsd = 1;
		}
		else {
			if (MouseY > 188*2 && MouseY < 226*2 && MouseX < 112*2) {
				mncsd = 2;
			}
			else {
				if (MouseY > 226*2 && MouseY < 264*2 && MouseX < 112*2) {
					mncsd = 3;
				}
				else {
					mncsd = 0;
				}
			}
		}
	}
	else {
		if (MouseY > 150 && MouseY < 188 && MouseX < 112) {
			menustartbuttonxpos += (50 - menustartbuttonxpos) / fpss * 10;
		}
		else {
			menustartbuttonxpos += (0 - menustartbuttonxpos) / fpss * 10;

		}
		if (MouseY > 188 && MouseY < 226 && MouseX < 112) {
			mssbtxps += (50 - mssbtxps) / fpss * 10;
		}
		else {
			mssbtxps += (0 - mssbtxps) / fpss * 10;

		}
		if (MouseY > 226 && MouseY < 264 && MouseX < 112) {
			msextxps += (50 - msextxps) / fpss * 10;
		}
		else {
			msextxps += (0 - msextxps) / fpss * 10;
		}
		if (MouseY > 150 && MouseY < 188 && MouseX < 112) {
			mncsd = 1;
		}
		else {
			if (MouseY > 188 && MouseY < 226 && MouseX < 112) {
				mncsd = 2;
			}
			else {
				if (MouseY > 226 && MouseY < 264 && MouseX < 112) {
					mncsd = 3;
				}
				else {
					mncsd = 0;
				}
			}
		}
	}
}