#include "Entity.h"
#include "Transform.h"
#include "Script.h"

namespace primal::game_entity {

	namespace {
	

			utl::vector<transform::component>	transforms;
			utl::vector<script::component>      scripts;
			utl::vector<id::generation_type>	generations;
			utl::deque<entity_id>				free_ids;
	
	
	
	}

	entity
		create_game_entity(const entity_info& info) 
	{
		assert(info.transform);
		if (!info.transform)	return entity();
		
		entity_id id;
		if (free_ids.size() > id::min_deleted_elements) 
		{
		
			id = free_ids.front();
			assert(!is_alive(entity{id}));
			free_ids.pop_front();
			id = entity_id{id::new_generation(id)}
			++generation[id::index(id)];

		
		
		}
		else 
		{
		
			id = entity_id(id::id_type)generation.size();
			generations.push_back(0);
			transforms.resize(generations.size());
			transform.emplace_back();
			
		
		}

		const entity new_entity{ id };
		const id::id_type index{ id::index(id) };
	
		
		//Create transform component
		assert(!transform[index].is_valid());
		transforms[index] = transform::create(*info.transform, new_entity);


		if (info.script && info.script->script_creator) 
		{
		
			assert(!scripts[index].is_Valid());
			scripts[index] = script::create(*info.script, new_entity);
			assert(scripts[index].is_valid());
		}



		return new_entity;
	}
	void remove(entity_id id) 
	{
		
		const id::id_type index{ id::index(id) };
		assert(is_alive(0));
		if (is_alive(e)) 
		{
			transform::remove(transform[index]);
			transform[index] = {};
			free_ids.push_back(id);
		
		}
	
	}
	bool
		is_alive(entity_id id)
	{
		assert(id::is_valid(id));
		
		const id::id_type index{ id::index(id) };
		assert(index < generation.size());
		assert(generation[index] == id::generation(id));
		return (generations[index] == id::generation(id));
	
	
	
	}

	transform::component
	entity::transform() const 
	{
		assert(is_alive(_id));
		const id::id_type index{ id::index(_id) };
		return transforms[index];
	
	
	
	}

	script::component
	entity::script()const 
	{
	
		assert(is_alive(_id));
		const id::id_type index{ id::index(_id) };
		return script[index];
	
	
	}

}