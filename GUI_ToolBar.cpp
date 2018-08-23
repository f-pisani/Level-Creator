#include "GUI_ToolBar.hpp"

/***************************************************************************************************
 * PUBLIC METHODS
 */
GUI_ToolBar::GUI_ToolBar(QWidget* parent) :
    QToolBar(parent),
    m_toolButton_object(new QToolButton(this)),
    m_toolButton_collider(new QToolButton(this)),
    m_toolButton_marker(new QToolButton(this)),
    m_toolButton_trigger(new QToolButton(this))
{
    // Object
    QActionGroup* toolButton_objectActionGroup = new QActionGroup(this);
    QAction* action = toolButton_objectActionGroup->addAction(QIcon("data/Object_Select.png"), "Object: Select");
    action->setToolTip("Select an object.");
    action->setCheckable(true);
    action->setData(QVariant(static_cast<int>(Tool_ID::Object_Select)));
    action = toolButton_objectActionGroup->addAction(QIcon("data/Object_Create.png"), "Object: Create");
    action->setToolTip("Create an object.");
    action->setCheckable(true);
    action->setData(QVariant(static_cast<int>(Tool_ID::Object_Create)));
    action = toolButton_objectActionGroup->addAction(QIcon("data/Object_Remove.png"), "Object: Remove");
    action->setToolTip("Remove an object.");
    action->setCheckable(true);
    action->setData(QVariant(static_cast<int>(Tool_ID::Object_Remove)));
    QMenu* toolButton_objectMenu = new QMenu(this);
    toolButton_objectMenu->addActions(toolButton_objectActionGroup->actions());
    m_toolButton_object->setPopupMode(QToolButton::InstantPopup);
    m_toolButton_object->setDefaultAction(toolButton_objectActionGroup->actions().at(0));
    m_toolButton_object->setMenu(toolButton_objectMenu);
    addWidget(m_toolButton_object);
    addSeparator();
    
    // Collider
    QActionGroup* toolButton_colliderActionGroup = new QActionGroup(this);
    action = toolButton_colliderActionGroup->addAction(QIcon("data/Collider_Select.png"), "Collider: Select");
    action->setToolTip("Select a collider.");
    action->setCheckable(true);
    action->setData(QVariant(static_cast<int>(Tool_ID::Collider_Select)));
    action = toolButton_colliderActionGroup->addAction(QIcon("data/Collider_Create.png"), "Collider: Create");
    action->setToolTip("Create a collider.");
    action->setCheckable(true);
    action->setData(QVariant(static_cast<int>(Tool_ID::Collider_Create)));
    action = toolButton_colliderActionGroup->addAction(QIcon("data/Collider_Remove.png"), "Collider: Remove");
    action->setToolTip("Remove a collider.");
    action->setCheckable(true);
    action->setData(QVariant(static_cast<int>(Tool_ID::Collider_Remove)));
    QMenu* toolButton_colliderMenu = new QMenu(this);
    toolButton_colliderMenu->addActions(toolButton_colliderActionGroup->actions());
    m_toolButton_collider->setPopupMode(QToolButton::InstantPopup);
    m_toolButton_collider->setDefaultAction(toolButton_colliderActionGroup->actions().at(0));
    m_toolButton_collider->setMenu(toolButton_colliderMenu);
    addWidget(m_toolButton_collider);
    addSeparator();
    
    // Marker
    QActionGroup* toolButton_markerActionGroup = new QActionGroup(this);
    action = toolButton_markerActionGroup->addAction(QIcon("data/Marker_Select.png"), "Marker: Select");
    action->setToolTip("Select a marker.");
    action->setCheckable(true);
    action->setData(QVariant(static_cast<int>(Tool_ID::Marker_Select)));
    action = toolButton_markerActionGroup->addAction(QIcon("data/Marker_Create.png"), "Marker: Create");
    action->setToolTip("Create a marker.");
    action->setCheckable(true);
    action->setData(QVariant(static_cast<int>(Tool_ID::Marker_Create)));
    action = toolButton_markerActionGroup->addAction(QIcon("data/Marker_Remove.png"), "Marker: Remove");
    action->setToolTip("Remove a marker.");
    action->setCheckable(true);
    action->setData(QVariant(static_cast<int>(Tool_ID::Marker_Remove)));
    QMenu* toolButton_markerMenu = new QMenu(this);
    toolButton_markerMenu->addActions(toolButton_markerActionGroup->actions());
    m_toolButton_marker->setPopupMode(QToolButton::InstantPopup);
    m_toolButton_marker->setDefaultAction(toolButton_markerActionGroup->actions().at(0));
    m_toolButton_marker->setMenu(toolButton_markerMenu);
    addWidget(m_toolButton_marker);
    addSeparator();
    
    // Trigger
    QActionGroup* toolButton_triggerActionGroup = new QActionGroup(this);
    action = toolButton_triggerActionGroup->addAction(QIcon("data/Trigger_Select.png"), "Trigger: Select");
    action->setToolTip("Select a trigger.");
    action->setCheckable(true);
    action->setData(QVariant(static_cast<int>(Tool_ID::Trigger_Select)));
    action = toolButton_triggerActionGroup->addAction(QIcon("data/Trigger_Create.png"), "Trigger: Create");
    action->setToolTip("Create a trigger.");
    action->setCheckable(true);
    action->setData(QVariant(static_cast<int>(Tool_ID::Trigger_Create)));
    action = toolButton_triggerActionGroup->addAction(QIcon("data/Trigger_Remove.png"), "Trigger: Remove");
    action->setToolTip("Remove a trigger.");
    action->setCheckable(true);
    action->setData(QVariant(static_cast<int>(Tool_ID::Trigger_Remove)));
    QMenu* toolButton_triggerMenu = new QMenu(this);
    toolButton_triggerMenu->addActions(toolButton_triggerActionGroup->actions());
    m_toolButton_trigger->setPopupMode(QToolButton::InstantPopup);
    m_toolButton_trigger->setDefaultAction(toolButton_triggerActionGroup->actions().at(0));
    m_toolButton_trigger->setMenu(toolButton_triggerMenu);
    addWidget(m_toolButton_trigger);
    
    
    connect(m_toolButton_object, SIGNAL(triggered(QAction*)), this, SLOT(toolButtonTriggered(QAction*)));
    connect(m_toolButton_collider, SIGNAL(triggered(QAction*)), this, SLOT(toolButtonTriggered(QAction*)));
    connect(m_toolButton_marker, SIGNAL(triggered(QAction*)), this, SLOT(toolButtonTriggered(QAction*)));
    connect(m_toolButton_trigger, SIGNAL(triggered(QAction*)), this, SLOT(toolButtonTriggered(QAction*)));
}


GUI_ToolBar::~GUI_ToolBar()
{
    delete m_toolButton_object;
    delete m_toolButton_collider;
    delete m_toolButton_marker;
    delete m_toolButton_trigger;
}


/***************************************************************************************************
 * PRIVATE SLOTS
 */
void GUI_ToolBar::toolButtonTriggered(QAction* action)
{
    Tool_ID selectedTool(static_cast<Tool_ID>(action->data().toInt()));
    
    if(selectedTool == Tool_ID::Object_Select || 
       selectedTool == Tool_ID::Object_Create || 
       selectedTool == Tool_ID::Object_Remove)
    {
        m_toolButton_object->setDefaultAction(action);
        
        m_toolButton_object->setChecked(true);
        m_toolButton_collider->setChecked(false);
        m_toolButton_marker->setChecked(false);
        m_toolButton_trigger->setChecked(false);
    }
    else if(selectedTool == Tool_ID::Collider_Select || 
            selectedTool == Tool_ID::Collider_Create || 
            selectedTool == Tool_ID::Collider_Remove)
    {
        m_toolButton_collider->setDefaultAction(action);
        
        m_toolButton_object->setChecked(false);
        m_toolButton_collider->setChecked(true);
        m_toolButton_marker->setChecked(false);
        m_toolButton_trigger->setChecked(false);
    }
    else if(selectedTool == Tool_ID::Marker_Select || 
            selectedTool == Tool_ID::Marker_Create || 
            selectedTool == Tool_ID::Marker_Remove)
    {
        m_toolButton_marker->setDefaultAction(action);
        
        m_toolButton_object->setChecked(false);
        m_toolButton_collider->setChecked(false);
        m_toolButton_marker->setChecked(true);
        m_toolButton_trigger->setChecked(false);
    }
    else if(selectedTool == Tool_ID::Trigger_Select || 
            selectedTool == Tool_ID::Trigger_Create || 
            selectedTool == Tool_ID::Trigger_Remove)
    {
        m_toolButton_trigger->setDefaultAction(action);
        
        m_toolButton_object->setChecked(false);
        m_toolButton_collider->setChecked(false);
        m_toolButton_marker->setChecked(false);
        m_toolButton_trigger->setChecked(true);
    }
    
    emit toolSelected(selectedTool);
    emit toolSelected(action->text());
}
