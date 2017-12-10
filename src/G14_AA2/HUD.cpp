#include "HUD.h"



HUD::HUD()
{
	vidas1 = { 25, 15, medidaVidas.x, medidaVidas.y };
	vidas2 = { 500, 15, medidaVidas2.x, medidaVidas2.y };
}


HUD::~HUD()
{
}

void HUD::DrawHud()
{
	Renderer::Instance()->PushImage(TEXT_VIDAS, vidas1);
	Renderer::Instance()->PushImage(TEXT_VIDAS2, vidas2);
}
