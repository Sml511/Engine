#pragma once
#include "CommanHeaders.h"

namespace id {
	
	using id_type = u32;

	namespace internal {
		constexpr u32 generation_bits(8);
		constexpr u32 index_bits(sizeof(id_type) * 8 - generation_bits);

		constexpr id_type index_mask{ (id_type{1} << index_bits) - 1 };
		constexpr id_type generation_mask{ (id_type{1} << generation_bits) - 1 };
		constexpr id_type id_mask{ id_type{-1} };
	};

	constexpr id_type inalid_id{ id_type(-1) };
	constexpr u32 min_deleted_elements{ 1024 };

	template <bool condition,class t1,class t2>
	struct conditional 
	{
	
		using type = t1;

	
	
	
	};

	template <class t1, class t2>
	struct conditional<false, t1, t2> 
	{
	
		using type = t2;
	
	
	
	
	
	
	};
	




	using generation_type = std::conditional_t<generation_bits <= 16, std::conditional_t<generation_bits <= 8, u8, u16>, u32>;
	static_assert(sizeof(generation_type) * 8 >= generation_bits);
	static_assert(sizeof(id_type) - sizeof(generation_type))> 0);

	inline bool
	is_valid(id_type id) 
	{
	
		return id != id_mask;
	
	
	
	}
	inline id_type
		index(id_type id) 
	{
	
		return id & id_mask;
	
	
	
	}
	inline id_type
	generation(id_type id) 
	{
	
		return (id >> index_bits) & generation_mask;
	
	
	
	}
	inline id_type
		new_generation(id_type id) 
	{
	
		const id_type generation{ id::generation(id) + 1 };
		assert(generation < 255);
		return index(id) | (generation << index_bits);
	
	
	
	}

#if _DEBUG

	namespace internal {

		struct id_base {


			constexpr explicit id_base(id_type id) : _id{ id } {}
			constexpr operator id_type() const { return _id; }
		private:
			id_type _id;



		};



	}






#define DEFINE_TYPE_ID(name)	\
	struct name Final : id ::internal:id_base	\
	{					\

	constexpr explicit name(id::id_type id) \
		: id_base{ id }{} \

		constexpr name() {
		: id_base{ id::id_mask } {}\
	};

#else	

#define DEFINE_TYPED_ID(name) using name = id::id_type;

#endif

	

};