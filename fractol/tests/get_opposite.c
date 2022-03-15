int	get_opposite(int trgb)
{
	int	r;
	int	g;
	int	b;

	r = 255 - ((trgb & (0xFF << 16)) >> 16);
	g = 255 - ((trgb & (0xFF << 8)) >> 8);
	b = 255 - (trgb & (0xFF));
	return ((trgb & (0xFF << 24)) | (r << 16) | (g << 8) | b);
}
