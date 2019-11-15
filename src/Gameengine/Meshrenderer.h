#include "Component.h"


class Material;

class MeshRenderer : public Component {
private:
	std::weak_ptr<MeshRenderer> mesh;


public:
	void onInit();
	void onDisplay();
	void setMesh(std::weak_ptr<MeshRenderer> mesh);
	void getMesh();
	//std::shared_ptr<MeshRenderer> getMesh();
	std::shared_ptr<Material> getMaterial();
};
