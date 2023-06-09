/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"





//==============================================================================
JuceReverbAudioProcessorEditor::JuceReverbAudioProcessorEditor(JuceReverbAudioProcessor& p)
    : AudioProcessorEditor(&p), audioProcessor(p),
    roomsizeSliderAttachment(audioProcessor.apvts, "RoomSize", roomSizeSlider),
    dampingSliderAttachment(audioProcessor.apvts, "Damping", dampingSlider),
    wetSliderAttachment(audioProcessor.apvts, "WetLevel", wetSlider),
    drySliderAttachment(audioProcessor.apvts, "DryLevel", drySlider),
    widthSliderAttachment(audioProcessor.apvts, "Width", widthSlider),
    reverbToggleAttachment(audioProcessor.apvts, "ReverbToggle", reverbToggle),
    convolutionToggleAttachment(audioProcessor.apvts, "ConvolutionToggle", convolutionToggle)

{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.

    addAndMakeVisible(loadBtn);
    addAndMakeVisible(reverbToggle);
    addAndMakeVisible(convolutionToggle);

    for (auto* comp : GetComps())
    {
        addAndMakeVisible(comp);
    }

    loadBtn.setButtonText("Load IR");
    loadBtn.onClick = [this]()
    {
        audioProcessor.LoadButtonPressed();

    };
    convolutionLabel.setText("Convolution Toggle",juce::dontSendNotification);
    reverbLabel.setText("Reverb Toggle", juce::dontSendNotification);

    roomSizeLabel.setText("Roomsize", juce::dontSendNotification);
       
       dampingLabel.setText("Damping", juce::dontSendNotification);
       
       wetLabel.setText("Wet level", juce::dontSendNotification);
       
       dryLabel.setText("Dry level", juce::dontSendNotification);
       
       widthLabel.setText("Width", juce::dontSendNotification);

    

    setSize (500, 500);
}

JuceReverbAudioProcessorEditor::~JuceReverbAudioProcessorEditor()
{
}

//==============================================================================
void JuceReverbAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

   
}

void JuceReverbAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    auto bounds = getLocalBounds();
    auto responseArea = bounds.removeFromTop(bounds.getHeight() * (1.0 / 5.0));

    auto reverbArea = bounds.removeFromLeft(bounds.getWidth() * 0.5);
    auto convolutionArea = bounds;

    reverbToggle.setBounds(reverbArea.removeFromTop(reverbArea.getHeight() * (1.0 / 6.0)));
    auto reverbToggleArea = reverbToggle.getBounds();

    reverbLabel.setBounds(reverbToggleArea.removeFromRight(reverbToggleArea.getWidth() * 0.8));

    roomSizeLabel.setBounds(reverbArea.removeFromTop(reverbArea.getHeight() * (1.0 / 10.0)));

    roomSizeSlider.setBounds(reverbArea.removeFromTop(reverbArea.getHeight() * (1.0 / 9.0)));

    dampingLabel.setBounds(reverbArea.removeFromTop(reverbArea.getHeight() * (1.0 / 8.0)));

    dampingSlider.setBounds(reverbArea.removeFromTop(reverbArea.getHeight() * (1.0 / 7.0)));

    dryLabel.setBounds(reverbArea.removeFromTop(reverbArea.getHeight() * (1.0 / 6.0)));

    drySlider.setBounds(reverbArea.removeFromTop(reverbArea.getHeight() * (1.0 / 5.0)));

    wetLabel.setBounds(reverbArea.removeFromTop(reverbArea.getHeight() * (1.0 / 4.0)));

    wetSlider.setBounds(reverbArea.removeFromTop(reverbArea.getHeight() * (1.0 / 3.0)));

    widthLabel.setBounds(reverbArea.removeFromTop(reverbArea.getHeight() * (1.0 / 2.0)));

    widthSlider.setBounds(reverbArea.removeFromTop(reverbArea.getHeight() * (1.0 / 1.0)));


    auto   convolutionButtonBounds = convolutionArea.removeFromTop(convolutionArea.getHeight() * (1.0 / 6.0));
    auto convolutionToggleBounds = convolutionButtonBounds.removeFromLeft(convolutionButtonBounds.getWidth() * 0.5);
    convolutionToggle.setBounds(convolutionToggleBounds);

    convolutionLabel.setBounds(convolutionToggleBounds.removeFromRight(convolutionToggleBounds.getWidth() * 0.8));

    loadBtn.setBounds(convolutionButtonBounds);


}


std::vector<juce::Component*> JuceReverbAudioProcessorEditor::GetComps()
{
    return
    {
        &roomSizeSlider,
        &dampingSlider,
        &wetSlider,
        &drySlider,
        &widthSlider,
        &convolutionLabel,
        &reverbLabel,
        &roomSizeLabel,
        &dampingLabel, 
        &wetLabel, 
        &dryLabel, 
        &widthLabel

    };
}

