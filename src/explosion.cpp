//  $Id$
//
//  SuperTuxKart - a fun racing game with go-kart
//  Copyright (C) 2004 Steve Baker <sjbaker1@airmail.net>
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#include <plib/ssg.h>
#include "explosion.hpp"
#include "world.hpp"
#include "projectile_manager.hpp"
#include "sound_manager.hpp"


Explosion::Explosion(sgCoord* coord) : ssgTransform()
{
    ssgCutout *cut = new ssgCutout();
    addKid(cut);
    // Make sure that the transform object does not get deleted when it is
    // removed from the scene graphs. This can happen when the explosion is
    // moved to the deletedExplosion list in the projecile_manager.
    ref();
    m_seq   = projectile_manager->getExplosionModel();
    cut->addKid(m_seq);
    init(coord);
}   // Explosion

//-----------------------------------------------------------------------------
void Explosion::init(sgCoord* coord)
{
    sound_manager->playSfx( SOUND_EXPLOSION );

    setTransform(coord);
    m_step = -1;
    world->addToScene(this);
}

//-----------------------------------------------------------------------------
void Explosion::update (float dt)
{

    if ( ++m_step >= m_seq->getNumKids() )
    {
        projectile_manager->FinishedExplosion();
        world->removeFromScene((ssgTransform*)this);
        return ;
    }

    m_seq -> selectStep ( m_step ) ;

}


