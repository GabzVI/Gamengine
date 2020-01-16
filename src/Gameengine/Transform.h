#ifndef _TRANSFORM_H
#define _TRANSFORM_H
#include "Component.h"
#include <memory>
#include <glm/glm.hpp>

class Entity;

///The transform class is inherited from the Component class,and it handles the translation and movements of objects in the scene.
///
class Transform : public Component
{

private:
	///objPos stroes position of each object in the scene.
	glm::vec3 _objPos;
	///objRot stroes rotation of each object in the scene.
	glm::vec3 _objRotation;
	///objScale stroes scale of each object in the scene.
	glm::vec3 _objScale;
	///move is a variable used so users can enter the amount they want the object to translate by.
	glm::vec4 move;

public:
	///3 Different functions were made to set the different local positions, rotations and scale of objects in scene.
	void setLocalpos(glm::vec3 _pos);
	void setLocalrot(glm::vec3 _rot);
	void setLocalScale(glm::vec3 _scale);
	///Translate function is used to change the model matrix and move the character depending on which axis its facing.
	void Translate(glm::vec4 _move);
	/// Rotate function is used to add rotation to an object per frame.
	void Rotate(glm::vec3 _rotate);
	///ChangePos function is used to change the position of the object by adding the amount the user has set to change. This will be used in the Player movement struct.
	void changePos(glm::vec3 _move);
	///getPosition returns the position of the object.
	glm::vec3 getPosition();
	///getRotation returns the posiiton of the rotation of the object.
	glm::vec3 getRotation();
	///getScale returns the scale of the object.
	glm::vec3 getScale();
	///Move() gets the model matrix of the object and times it by the move variable to translate the object.
	glm::vec3 Move();
	///Returns the Model matrix of the object created.
	glm::mat4 getModelmatrix();


};

#endif 