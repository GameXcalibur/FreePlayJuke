#ifndef EQUALIZER_H
#define EQUALIZER_H

#include <vlc/vlc.h>

class equalizer
{
private:

    libvlc_equalizer_t* jbEqualizer;

public:
    equalizer();
    ~equalizer();
    void setEqualizer(libvlc_media_player_t *mp);
    void setPreamp(float);
    int getPreamp(void);
    int getBand( unsigned bandNum);
    void setBand(float val, unsigned bandNum);
    const char* getCurPreset(unsigned index);
    void setPreset(unsigned index);

};

#endif // EQUALIZER_H
