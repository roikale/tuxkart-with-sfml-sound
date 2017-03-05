
#include "tuxkart.h"

struct Sound
{
   char *fname ;
   sf::SoundBuffer *s ;
} ;


static Sound sfx [] =
{
  { "wavs/ugh.wav"	, NULL },
  { "wavs/boing.wav"	, NULL },
  { "wavs/bonk.wav"	, NULL },
  { "wavs/burp.wav"	, NULL },
  { "wavs/laser.wav"	, NULL },
  { "wavs/ow.wav"	, NULL },
  { "wavs/wee.wav"	, NULL },
  { "wavs/explosion.wav", NULL },
  { "wavs/bzzt.wav"	, NULL },
  { "wavs/horn.wav"	, NULL },
  { "wavs/shoomf.wav"	, NULL },
  { NULL, NULL }
} ;

static int music_off = FALSE ;
static int   sfx_off = FALSE ;

void SoundSystem::disable_music ()
{
  music . stop () ;

  music_off = TRUE  ;
}


void SoundSystem::change_track ( char *fname )
{
  if ( fname == NULL )
    fname = "" ;

  if ( strcmp ( fname, current_track ) != 0  )
  {
    strcpy ( current_track, fname ) ;

    if ( ! music_off )
      enable_music  () ;
  }
}

void SoundSystem::enable_music ()
{
  music . stop() ;

  music . openFromFile( current_track ) ;
  music . setLoop(true) ;
  music . play() ;
 
  music_off = FALSE ;
}


void SoundSystem::disable_sfx () { sfx_off = TRUE  ; }
void SoundSystem:: enable_sfx () { sfx_off = FALSE ; }



void SoundSystem::playSfx ( int sfx_num )
{
  if (  sfx_off )
      return;

  Sound *curr_sfx = &( sfx[sfx_num] ) ;
  effect . setBuffer( *(curr_sfx->s) ) ;
  effect . play() ;
}


SoundSystem::SoundSystem ()
{
  /* Load all SFX files */
  for ( Sound *currsfx = &(sfx[0]) ; currsfx -> fname != NULL ; currsfx++ ) {
    sf::SoundBuffer *sb = new sf::SoundBuffer;

    sb -> loadFromFile ( currsfx->fname );

    currsfx -> s  = sb;
  }

  enable_sfx   () ;
  change_track ( "wavs/Boom_boom_boom.wav" ) ;
  enable_music () ;
}


void SoundSystem::update ()
{
}

