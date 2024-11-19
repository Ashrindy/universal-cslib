#pragma once
#include <ucsl/math.h>
#include <ucsl/containers/arrays/array.h>
#include <ucsl/resources/object-world/v2.h>
#include <simple-reflection/simple-reflection.h>
#include <ucsl-reflection/operators.h>
#include <ucsl-reflection/reflections/basic-types.h>

namespace ucsl::resources::object_world::v2::reflections {
    using namespace simplerfl;
    using namespace ucsl::reflection;

    namespace impl = ucsl::resources::object_world::v2;

    using ObjectTransformData = structure<impl::ObjectTransformData, "ObjectTransformData", void,
        field<math::Position, "position">,
        field<math::Position, "rotation">
    >;

    using ComponentData = structure<impl::ComponentData, "ComponentData", void,
        field<erased<unsigned long long>, "unk1">,
        field<const char*, "type">,
        field<unsigned long long, "size">,
        field<component_data_rflclass<ComponentData, [](const ComponentData& parent) -> const char* { return parent.type; }>*, "data" >
    >;

    using ObjectData = structure<impl::ObjectData, "ObjectData", void,
        field<erased<unsigned int>, "flags">,
        field<const char*, "gameObjectClass">,
        field<const char*, "name">,
        field<objectids::ObjectIdV1, "id">,
        field<objectids::ObjectIdV1, "parentID">,
        field<ObjectTransformData, "transform">,
        field<ObjectTransformData, "localTransform">,
        field<containers::arrays::Array<ComponentData*>, "componentData">,
        field<spawner_data_rflclass<ObjectData, [](const ObjectData& parent) -> const char* { return parent.gameObjectClass; }>*, "spawnerData" >
    >;

    using ObjectWorldData = structure<impl::ObjectWorldData, "ObjectWorldData", void,
        field<erased<unsigned int>, "unk1">,
        field<erased<unsigned int>, "unk2">,
        field<erased<unsigned char>, "flags">,
        field<containers::arrays::Array<ObjectData*>, "objects">
    >;
}

namespace simplerfl {
    template<> struct canonical<ucsl::resources::object_world::v2::ObjectTransformData> { using type = ucsl::resources::object_world::v2::reflections::ObjectTransformData; };
    template<> struct canonical<ucsl::resources::object_world::v2::ComponentData> { using type = ucsl::resources::object_world::v2::reflections::ComponentData; };
    template<> struct canonical<ucsl::resources::object_world::v2::ObjectData> { using type = ucsl::resources::object_world::v2::reflections::ObjectData; };
    template<> struct canonical<ucsl::resources::object_world::v2::ObjectWorldData> { using type = ucsl::resources::object_world::v2::reflections::ObjectWorldData; };
}
