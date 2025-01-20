#pragma once
#include <ucsl/math.h>
#include <simple-reflection/simple-reflection.h>
#include <ucsl-reflection/operators.h>
#include <ucsl-reflection/reflections/basic-types.h>

// reversed from files

namespace ucsl::resources::converse_meta::v2::reflections {
    using namespace simplerfl;
	using namespace ucsl::reflection;

	namespace impl = ::ucsl::resources::converse_meta::v2;

	using Crop = structure<impl::Crop, "Crop", void,
		field<float, "left">,
		field<float, "top">,
		field<float, "right">,
		field<float, "bottom">
	>;

    using Icon = structure<impl::Icon, "Icon", void,
		field<const char*, "iconName">,
		field<const char*, "imageName">,
		field<float, "unk0">,
		field<float, "unk1">,
		field<float, "unk2">,
		field<float, "unk3">,
		field<Crop, "crop">,
		field<long long, "unk4">,
		field<long long, "unk5">
	>;

    using IconInfo = structure<impl::IconInfo, "IconInfo", void,
		field<int, "iconCount">,
		field<dynamic_carray<Icon*, impl::IconInfo, [](const impl::IconInfo& parent) -> size_t { return parent.iconCount; }>*, "icons">,
        field<int, "resourceCount">,
		field<dynamic_carray<const char*, impl::IconInfo, [](const impl::IconInfo& parent) -> size_t { return parent.resourceCount; }>*, "resourceNames">
	>;

    using TypeFace = structure<impl::TypeFace, "TypeFace", void,
		field<int, "parentCount">,
		field<dynamic_carray<const char*, impl::TypeFace, [](const impl::TypeFace& parent) -> size_t { return parent.parentCount; }>*, "parents">,
		field<const char*, "name0">,
		field<const char*, "name1">,
		field<float, "unk0">,
		field<float, "unk1">,
		field<float, "unk2">,
		field<float, "unk3">
	>;

    using TypeFaceInfo = structure<impl::TypeFaceInfo, "TypeFaceInfo", void,
		field<int, "typeFaceCount">,
		field<dynamic_carray<TypeFace*, impl::TypeFaceInfo, [](const impl::TypeFaceInfo& parent) -> size_t { return parent.typeFaceCount; }>*, "typeFaces">
	>;

    using CnvrsMetaData = structure<impl::CnvrsMetaData, "CnvrsMetaData", void,
        field<unsigned int, "version">,
        field<TypeFaceInfo*, "typeFaceInfo">,
        field<IconInfo*, "iconInfo">
    >;
}

namespace simplerfl {
	template<> struct canonical<ucsl::resources::converse_meta::v2::Crop> { using type = ucsl::resources::converse_meta::v2::reflections::Crop; };
	template<> struct canonical<ucsl::resources::converse_meta::v2::Icon> { using type = ucsl::resources::converse_meta::v2::reflections::Icon; };
	template<> struct canonical<ucsl::resources::converse_meta::v2::IconInfo> { using type = ucsl::resources::converse_meta::v2::reflections::IconInfo; };
	template<> struct canonical<ucsl::resources::converse_meta::v2::TypeFace> { using type = ucsl::resources::converse_meta::v2::reflections::TypeFace; };
	template<> struct canonical<ucsl::resources::converse_meta::v2::TypeFaceInfo> { using type = ucsl::resources::converse_meta::v2::reflections::TypeFaceInfo; };
	template<> struct canonical<ucsl::resources::converse_meta::v2::CnvrsMetaData> { using type = ucsl::resources::converse_meta::v2::reflections::CnvrsMetaData; };
}