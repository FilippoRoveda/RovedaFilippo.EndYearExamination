#pragma once
#include "Component.h"
#include "RectTransform.h"


/**
* \brief Component that generate animation by changing texture in a spritesheet.
*/
class AnimationComponent : public Component
{
public:
	sf::IntRect uvRect;


private:
	//Total image count in a sprite sheet.
	sf::Vector2u imgCount;

	//Counter of the current selected image in a sprite sheet.
	sf::Vector2u currentImg;

	//Total elapsed time from the last texture switch
	float totalTime;
	//Time to wait before switch texture in animation
	float switchTime;

	//Animated RectTransform component
	RectTranform* animated;

	//Member to record current texture handled
	const sf::Texture* currentTexture;



public:
	/**
	* \brief Constructor. Select the handled RectTransform, give a initial imageCount and decide the switch delay time between texture changes.
	* \return void
	*/
	AnimationComponent(RectTranform* texture, sf::Vector2u imgCount, float switchTime);
	~AnimationComponent();

	/**
* \brief Swtich animation every defined switch time.
* \return void
*/
	void On_Update(const float delta_time) override;


};