#include "equalizer.h"
#include <QDebug>

equalizer::equalizer()
{
    jbEqualizer = libvlc_audio_equalizer_new();

}

equalizer::~equalizer()
{

    libvlc_audio_equalizer_release(jbEqualizer);

}

void equalizer::setEqualizer(libvlc_media_player_t *mp){

    libvlc_media_player_set_equalizer(mp, jbEqualizer);


}
int equalizer::getPreamp(void){

    return libvlc_audio_equalizer_get_preamp(jbEqualizer);
}

void equalizer::setPreamp(float val){

    libvlc_audio_equalizer_set_preamp(jbEqualizer,val );

}
int equalizer::getBand( unsigned bandNum){

    return libvlc_audio_equalizer_get_amp_at_index(jbEqualizer, bandNum );
}

void equalizer::setBand(float val, unsigned bandNum){

    libvlc_audio_equalizer_set_amp_at_index( jbEqualizer, val, bandNum );

}
const char* equalizer::getCurPreset(unsigned index){

     return libvlc_audio_equalizer_get_preset_name(index);

}

void equalizer::setPreset(unsigned index){

    jbEqualizer = libvlc_audio_equalizer_new_from_preset(index);

}


