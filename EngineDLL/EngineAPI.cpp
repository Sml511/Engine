#ifndef EDITOR_INTERFACE
#define EDITOR_INTERFACE extern "C" __declspec(dllexport)



#endif

#include "CommanHeaders.h"
#include "Entity.h"
#include "../Engine/Entity.h"
#include "../Engine/Transform.h"

using namespace primal;

namespace 
{
	struct transform_component {
	
	
		f32 position[3];
		f32 rotation[3];
		f32 scale[3];
		
		transform::init_info to_init_info() 
		{
			using namespace DirectX;
			transform::init_info info {};
			memcpy(&info.position[0], &position[0], sizeof(f32) * _countof(position));
			memcpy(&info.scale[0], &scale[0], sizeof(f32) * _countof(scale));
			XMFLOAT3A rot{ &rotation[0] };
			XMVECTOR qual{ XMQuaternRotationRollPitchYawFromVector{XMLoadFloat3A(&rot)}};
			XMFLOAT4A rot_qual{};
			XMStoreFloat4A(&rot_qual, qual);

			memcpy(&info.rotation[0], &rot_qual.x, sizeof(f32) * _countof(rotation));
			return info;


		}
	
	
	};
	struct game_entity_descriptor 
	{
	
	
		transform_component transform;
	
	
	
	};

	game_entity::entity entity_from_id(id::id_type id)
	{

		return game_entity::entity{ game_entity::entity_id{id } };
	};


	};

}


EDITOR_INTERFACE
id::id_type  
CreateGameEntity(game_entity_descriptor * e) 
{

	assert(e);
	game_entity_descriptor& desc{ *e };
	transform::init_info transform_info{ (desc.transform.to_init_info()) };

	game_entity::entity_info entity_info
	{

		&transform_info,


	};

	return game_entity::create_game_entity(entity_info).get_id();
}

ENDITOR_INTERFANCE
RemoveGameEntity(id::id_type id) 
{

	assert(id::is_valid(id));
	game_entity::remove_game_entity(entity_from_id(id));



}


