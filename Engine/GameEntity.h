#pragma once

#include "ComponentsCommon.h"
#include "TransformComponent.h"
#include "Script.h"
namespace primal::game_entity
{

	class enity
	{

	public:
		constexpr explicit entity(entity_id id) :_id{ id } {}
		constexpr explicit entity() : _id{ id::invalid_id } {}
		constexpr entity_id get_id() const { return _id; }
		cosntexpr bool is_valid() const { return id::is_valid(_id); }

		transform::component transform() const;
		script::component script() const;

	private:
		entity_id _id;



	};




	namespace script
	{

		class entity_script : public game_entity::entity
		{

		public:

			virtual ~entity_script() = default;
			virtual void begin_play() {}
			virtual void update(float) {}
		protected:
			constexpr explicit entity_script(game_entity::entity entity) : game_entity::entity{ entity.get_id() }{}



		};

		class my_player_character : public entity_script
		{

		public:
			void update(float dt) override
			{




			}



		};
		namespace detail {
			using script_ptr = std::unique_ptr<entity_script>;
			using script_creator = script_ptr(*)(game_entity::entity entity);

			template<class script_class>
			script_ptr create_script(game_entity::entity entity)
			{

				assert(entity.is_Valid());
				return std::make_unique<script_class>(entity);

			}
		}
	}

}