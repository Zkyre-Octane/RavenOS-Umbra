'home', 8x8px
const unsigned char epd_bitmap_home [] PROGMEM = {
	0x18, 0x3c, 0x7e, 0xff, 0x66, 0x66, 0x66, 0x7e
};

// Array of all bitmaps for convenience. (Total bytes used to store images in PROGMEM = 32)
const int epd_bitmap_allArray_LEN = 1;
const unsigned char* epd_bitmap_allArray[1] = {
	epd_bitmap_home
};
