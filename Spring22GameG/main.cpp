#include "../Space/Space.h"

//when we use the namespace, we need to add namespace prefix before GameApp
class springApp : public Space::SpaceApp
{

};

//this will be a marco we will define, user will first inheir our AirApp then supply it to AIR_APPLICATION_START
GAME_AIRPLICATION_START(springApp);