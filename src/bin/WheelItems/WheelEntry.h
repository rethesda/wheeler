#pragma once
#include "WheelItem.h"
#include <vector>

class WheelEntry
{
	// this don't inherit WheelItem because it is a container of that
public:
	void DrawSlot(ImVec2 a_center, bool a_hovered, RE::TESObjectREFR::InventoryItemMap& a_imap);
	
	void DrawHighlight(ImVec2 a_center, RE::TESObjectREFR::InventoryItemMap& a_imap);

	bool IsActive(RE::TESObjectREFR::InventoryItemMap& a_inv);
	bool IsAvailable(RE::TESObjectREFR::InventoryItemMap& a_inv);

	void ActivateItemLeft();
	void ActivateItemRight();

	void PrevItem();
	void NextItem();

	WheelEntry() 
	{
		_selectedItem = 0;
	}

	~WheelEntry()
	{
		for (auto& item : _items) {
			delete item;
		}
	}
	std::vector<WheelItem*> _items;

private:
	int _selectedItem;
};
