// Created by felix on 6/2/2019.
#include "Enemy.h"


Enemy::Enemy(sf::Texture *texture, sf::Vector2u windowBounds,
             sf::Vector2f position,
             sf::Vector2f direction,
             int type, int hpMax)
{
    this->texture = texture;
    this->sprite.setTexture(*this->texture);
    this->sprite.setScale(EnemyConfig::ENEMY_SCALE,EnemyConfig::ENEMY_SCALE);
    this->type = type;
    this->sprite.setPosition(position);

    this->hpMax = hpMax;
    this->hp = this->hpMax;
/*
    this->damageMax = damageMax;
    this->damageMin = damageMin;
*/
}

Enemy::~Enemy() {

}

void Enemy::takeDamage(int damage) {
    this->hp -= damage;
    if(this->hp <= 0){
        this->hp = 0;
    }
}

void Enemy::update(sf::Vector2u windowBounds) {
    switch (this->type) {
        case 0:
            this->sprite.move(-EnemyConfig::ENEMY_SPEED,0.0f);
            break;
        default: break;
    }

}

void Enemy::draw(sf::RenderTarget &target) {
    target.draw(this->sprite);

}