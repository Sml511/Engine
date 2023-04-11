#pragma once
#include "ComponentsCommon.h"

namespace primal::script
{
	DEFINE_TYPE_ID(script_id);
	class component final
	{

	public:
		constexpr explicit component(script_id id) :_id{ id } {}
		constexpr explicit component() : _id{ id::invalid_id } {}
		constexpr script_id get_id() const { return _id; }
		cosntexpr bool is_valid() const { return id::is_valid(_id); }

		math::v4 rotation() const;
		math::v4 position() const;
		math::v3 scale()	const;


	private:
		script_id _id;


	};




}
