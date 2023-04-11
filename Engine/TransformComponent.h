#pragma once
#include "ComponentsCommon.h"

namespace primal::transform 
{
	class component final 
	{
	
	public:
		constexpr explicit component(transform_id id) :_id{ id } {}
		constexpr explicit component() : _id{ id::invalid_id } {}
		constexpr transform_id get_id() const { return _id; }
		cosntexpr bool is_valid() const { return id::is_valid(_id); }

		math::v4 rotation() const;
		math::v4 position() const;
		math::v3 scale()	const;


	private:
		transform_id _id;
	
	
	};




}