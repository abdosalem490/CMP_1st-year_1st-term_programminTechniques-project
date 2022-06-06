#include "Component.h"

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;	
}


GraphicsInfo Component::GetGraphicsInfo() const {
	return m_GfxInfo;
}

bool Component::GetSelected() const {

	return selected;

}

void Component::SetSelected(bool s) {

	selected = s;

}

void Component::SetGraphicsInfo(GraphicsInfo arg_gfx) {

	m_GfxInfo = arg_gfx;

}

void Component::SetLabel(string s) {
	m_Label = s;
}

string Component::GetLabel() const {
	return m_Label;
}

Component::Component()
{}

Component::~Component()
{}

