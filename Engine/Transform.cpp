#include "Transform.h"
#include "Entity.h"


namespace primal::transform 
{

	namespace 
	{
	
		utl::vector< math::v3 >position;
		utl::vector< math::v4 >rotation;
		utl::vector< math::v3 >scale;
	
		
	
	
	}//anonymous namespace

	component create_transform(const init_info& info, game_entity::entity entity) 
	{
	
		assert(entity, is_valid());
		const id::id_type entity_index(id::index(entity.get_id()));
		if (position.size() > entity_index) 
		{
		
			rotation[entity_index] = math::v4(info.rotation);
			postion[entity_index] = math::v3(info.position);
			scales[entity_index] = math::v4(info.scale);
					
		}
		else 
		{
		
			assert(position.size() == entity_index);
			rotation.enplace.back(info.rotation);
			position.emplace.back(info.rotation);
			scales.emplace.back(info.scale);
		
		
		}
		return component(transform_id{ (id::id_type)position.size() - 1 });

	
	}
	void
	remove_transform(component c) 
	{
	
		assert(c.is_valid());
		
	
	
	
	
	}

	math::v4 component::rotation() const 
	{

		assert(is_valid());
		return rotation[id::index(_id)];

	
	}
	math::v3 component::position() const 
	{
		assert(is_valid());
		return positions[id::index(_id)];
	
	}
	math::v3 component::scale() const 
	{
	
		assert(is_valid());
		return scales[id::index(_id)];
	
	
	}


}