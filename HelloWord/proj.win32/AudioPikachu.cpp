#include "AudioPikachu.h"
#include "cocos2d.h"
#include "AudioEngine.h"

int AudioPikachu::backgroundMusic = -1;

float AudioPikachu::backgroundVolume = 1.0f;

float AudioPikachu::effectVolume = 1.0f;

void AudioPikachu::playBackgroundMusic()
{
	backgroundMusic = cocos2d::experimental::AudioEngine::play2d("audio.mp3", true, backgroundVolume);
}

void AudioPikachu::stopBackgroundMusic()
{
	cocos2d::experimental::AudioEngine::stop(backgroundMusic);
}

void AudioPikachu::setBackgroundVolume(float volume)
{
	backgroundVolume = volume;
	cocos2d::experimental::AudioEngine::setVolume(backgroundMusic, volume);
}

void AudioPikachu::playSelectPokemonSoundEffect()
{
	cocos2d::experimental::AudioEngine::play2d("audio.mp3", false, effectVolume);
}

void AudioPikachu::playRemovePokemonSoundEffect()
{
	cocos2d::experimental::AudioEngine::play2d("audio.mp3", false, effectVolume);
}

void AudioPikachu::setEffectVolume(float volume)
{
	effectVolume = volume;
}