/*
 * Copyright 2012 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#ifndef _DOOR_ITEM_HH_
#define _DOOR_ITEM_HH_

#include "gazebo/gui/qt.h"
#include "gazebo/gui/model_editor/RectItem.hh"
#include "gazebo/gui/model_editor/BuildingItem.hh"

namespace gazebo
{
  namespace gui
  {
    class RectItem;

    class BuildingItem;

    class WindowDoorInspectorDialog;

    class DoorItem : public RectItem, public BuildingItem
    {
      Q_OBJECT

      /// \brief Constructor
      public: DoorItem();

      /// \brief Destructor
      public: ~DoorItem();

      // Documentation inherited
      public: virtual QVector3D GetSize() const;

      // Documentation inherited
      public: virtual QVector3D GetScenePosition() const;

      // Documentation inherited
      public: virtual double GetSceneRotation() const;

      // Documentation inherited
      private: virtual void paint(QPainter *_painter,
          const QStyleOptionGraphicsItem *_option, QWidget *_widget);

      // Documentation inherited
      private: void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *_event);

      /// \brief Qt callback when the changes are to be applied
      private slots: void OnApply();

      /// \brief Qt callback to open the door inspector
      private slots: void OnOpenInspector();

      /// \brief Qt callback to delete this door item
      private slots: void OnDeleteItem();

      /// \brief Emit door changed signals
      private: void DoorChanged();

      /// \brief Emit size changed signals
      private: void SizeChanged();

      /// \brief Door depth in pixels
      private: double doorDepth;

      /// \brief Door height in pixels
      private: double doorHeight;

      /// \brief Door width in pixels
      private: double doorWidth;

      /// \brief Door elevation in pixels
      private: double doorElevation;

      /// \brief Door scene position in pixels
      private: QPointF doorPos;

      /// \brief Scale for converting to metric units
      private: double scale;

      /// \brief Door inspector
      private: WindowDoorInspectorDialog *inspector;
    };
  }
}

#endif
