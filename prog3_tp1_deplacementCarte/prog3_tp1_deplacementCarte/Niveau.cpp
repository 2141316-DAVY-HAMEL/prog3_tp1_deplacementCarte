#include "Niveau.h"

int Niveau::getIndexCarte(Point2D position)
{
	// Retourne l'index de la carte � partir de la position
	return position.getY() * constantes::dimension + position.getX();
}

Niveau::Niveau(int* carte, std::string nomCreature, Point2D positionDepart)
{
	m_carte = carte;
	m_creature = new Creature(nomCreature, positionDepart);
}

Niveau::~Niveau()
{
	delete[] m_carte;
	delete m_creature;
}

int* Niveau::getCarte()
{
	return m_carte;
}

std::string Niveau::getNomCreature()
{
	return m_creature->getNom();
}

void Niveau::getDeplacementPossible(bool* tabDeplacements)
{
	// R�cup�re la position actuelle de la cr�ature
	Point2D positionActuelle = *(m_creature->getPosition());
	// V�rifie pour chaque direction si la cr�ature peut s'y d�placer
	// HAUT
	if (m_carte[getIndexCarte(Point2D(positionActuelle.getX(), positionActuelle.getY() - 1))] == 0)
	{
		tabDeplacements[2] = true;
	}
	else
	{
		tabDeplacements[2] = false;
	}
	// BAS
	if (m_carte[getIndexCarte(Point2D(positionActuelle.getX(), positionActuelle.getY() + 1))] == 0)
	{
		tabDeplacements[3] = true;
	}
	else
	{
		tabDeplacements[3] = false;
	}
	// GAUCHE
	if (m_carte[getIndexCarte(Point2D(positionActuelle.getX() - 1, positionActuelle.getY()))] == 0)
	{
		tabDeplacements[0] = true;
	}
	else
	{
		tabDeplacements[0] = false;
	}
	// DROITE
	if (m_carte[getIndexCarte(Point2D(positionActuelle.getX() + 1, positionActuelle.getY()))] == 0)
	{
		tabDeplacements[1] = true;
	}
	else
	{
		tabDeplacements[1] = false;
	}
	

}

void Niveau::deplacerCreature(constantes::Direction direction)
{
	// R�cup�re la position actuelle de la cr�ature
	Point2D positionActuelle = *(m_creature->getPosition());
	// V�rifie la direction choisie et d�place la cr�ature
	switch (direction)
	{
	case constantes::Direction::haut:
		m_creature->deplacerCreature(positionActuelle.getX(), positionActuelle.getY() - 1);
		break;
	case constantes::Direction::bas:
		m_creature->deplacerCreature(positionActuelle.getX(), positionActuelle.getY() + 1);
		break;
	case constantes::Direction::gauche:
		m_creature->deplacerCreature(positionActuelle.getX() - 1, positionActuelle.getY());
		break;
	case constantes::Direction::droite:
		m_creature->deplacerCreature(positionActuelle.getX() + 1, positionActuelle.getY());
		break;
	default:
		break;
	}
	
}