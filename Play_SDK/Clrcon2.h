// ClrCon2.h

#ifndef _COLORCON_
#define _COLORCON_

typedef long rgtype;
typedef long rglutype;
typedef long yuvtype;
typedef long yuvlutype;



class ColorConversion 
{
	public:
		ColorConversion();

	void	Convert2YUV(BYTE* source,BYTE* dest_yc,BYTE* destA , int w);
	void	Convert2RGB(BYTE* dest,BOOL destAlpha, BYTE* source, BOOL sourceAlpha, int w);
	private:
		yuvlutype	rylup[256];
		yuvlutype	gylup[256];
		yuvlutype	bylup[256];

    yuvlutype rulup[256];
		yuvlutype	rvlup[256];

		yuvlutype	gulup[256];
		yuvlutype	gvlup[256];

		yuvlutype	bulup[256];
    yuvlutype bvlup[256];

		rglutype	yrl[256];		// y red lookup
		rglutype	ygl[256];
		rglutype	ybl[256];

		rglutype	url[256];
		rglutype	ugl[256];
		rglutype	ubl[256];

		rglutype	vrl[256];
		rglutype	vgl[256];
		rglutype	vbl[256];


};

#endif // _COLORCON_
