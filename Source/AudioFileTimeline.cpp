/*
    Copyright (C) 2018 Jonathon Racz

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "AudioFileTimeline.h"

AudioFileTimeline::AudioFileTimeline (AudioFormatManager& formatManagerToUse,
    AudioThumbnailCache& cacheToUse, Value sampleRate, Value windowLeft,
    Value windowRight, Value lengthSeconds, Value filename)
    : waveform (formatManagerToUse, cacheToUse, windowLeft, windowRight,
          filename),
      navigationControl (sampleRate, windowLeft, windowRight, lengthSeconds,
          AudioFileNavigationControl::ControlFrameOfReference::windowLength)
{
    addAndMakeVisible (waveform);
    addAndMakeVisible (navigationControl);
}

void AudioFileTimeline::resized()
{
    waveform.setBounds (getLocalBounds());
    navigationControl.setBounds (getLocalBounds());
}
