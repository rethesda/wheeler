#include "bin/Rendering/Drawer.h"
#include "bin/Rendering/TextureManager.h"
#include "WheelItemShout.h"

WheelItemShout::WheelItemShout(RE::TESShout* a_shout)
{
	this->_shout = a_shout;
	this->_texture = Texture::GetIconImage(Texture::icon_image_type::shout);
}

void WheelItemShout::DrawSlot(ImVec2 a_center, bool a_hovered, RE::TESObjectREFR::InventoryItemMap& a_imap, DrawArgs a_drawArgs)
{
	{
		using namespace Config::Styling::Item::Slot;
		Drawer::draw_text(a_center.x + Text::OffsetX, a_center.y + Text::OffsetY,
			this->_shout->GetName(), C_SKYRIMWHITE, Text::Size, a_drawArgs);
	}

	Drawer::draw_texture(_texture.texture,
		ImVec2(a_center.x, a_center.y),
		Config::Styling::Item::Slot::Texture::OffsetX,
		Config::Styling::Item::Slot::Texture::OffsetY,
		ImVec2(_texture.width * Config::Styling::Item::Slot::Texture::Scale, _texture.height * Config::Styling::Item::Slot::Texture::Scale),
		C_SKYRIMWHITE,
		a_drawArgs);
}

void WheelItemShout::DrawHighlight(ImVec2 a_center, RE::TESObjectREFR::InventoryItemMap& a_imap, DrawArgs a_drawArgs)
{
	using namespace Config::Styling::Item::Highlight;

	Drawer::draw_text(a_center.x + Text::OffsetX, a_center.y + Text::OffsetY,
		_shout->GetName(), C_SKYRIMWHITE, Text::Size, a_drawArgs);

	Drawer::draw_texture(_texture.texture,
		ImVec2(a_center.x, a_center.y),
		Config::Styling::Item::Highlight::Texture::OffsetX,
		Config::Styling::Item::Highlight::Texture::OffsetY,
		ImVec2(_texture.width * Config::Styling::Item::Highlight::Texture::Scale, _texture.height * Config::Styling::Item::Highlight::Texture::Scale),
		C_SKYRIMWHITE,
		a_drawArgs);
}

bool WheelItemShout::IsActive(RE::TESObjectREFR::InventoryItemMap& a_inv)
{
	RE::PlayerCharacter* pc = RE::PlayerCharacter::GetSingleton();
	if (!pc) {
		return false;
	}
	RE::TESForm* selectedPower = pc->GetActorRuntimeData().selectedPower;
	if (selectedPower) {
		return selectedPower->GetFormID() == this->_shout->GetFormID();
	}
	return false;
}

bool WheelItemShout::IsAvailable(RE::TESObjectREFR::InventoryItemMap& a_inv)
{
	return false;
}

void WheelItemShout::ActivateItemSecondary()
{
	RE::PlayerCharacter* pc = RE::PlayerCharacter::GetSingleton();
	if (!pc) {
		return;
	}
}

void WheelItemShout::ActivateItemPrimary()
{
	RE::PlayerCharacter* pc = RE::PlayerCharacter::GetSingleton();
	if (!pc) {
		return;
	}
}

void WheelItemShout::SerializeIntoJsonObj(nlohmann::json& a_json)
{
	a_json["type"] = WheelItemShout::ITEM_TYPE_STR;
	a_json["formID"] = this->_shout->GetFormID();
}

void WheelItemShout::ActivateItemSpecial()
{
}