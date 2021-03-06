<?php

# Which site
/** check if URL is our site - todo: use file cache */
function env_site_id($domain) {
  $domain = str_replace(".dev", ".com", $domain); // doesn't work for .nl
  //die("domain=$domain");
  switch($domain) {
    case 'patina.tech'                    : return 100;
    case 'apartments-for-rent.com'        : return 10;
    case 'youramsterdamhousing.com'       : return 109;
    case 'canalapartments.com'            : return 211;
    case 'syspensa.com'                   : return 213;
    case 'jordaanapartmentsamsterdam.com' : return 216;
    case 'kerrygroneng.com'               : return 231;
    case 'vpatina.com'                    : return 247;
    case 'hitabrick.com'                  : return 263;
    case 'evolutionsports.nl'             : return 265;
    case 'elastictools.io'                : return 267;
    default: return 0;
  }
}


# Which page
function route($app) {
  
  $router = new AltoRouter();
  $router->addMatchTypes(array('n' => '[a-zA-Z0-9-_]+'));

  /** Test Site */
  $router->map( 'GET', '/testpage', 'mytest', 'mytestpage');
  
  $router->map( 'GET', '/backend', 'gallery_backend', 'backend');
  $router->map( 'GET', '/backend/[a:subview]/[i:id]', 'gallery_backend', 'backend:subview:id');
  $router->map( 'GET', '/backend/[a:subview]/[i:id]/[a:action]', 'gallery_backend', 'backend:subview:id:action');
  $router->map( 'GET', '/backend/[a:subview]/[i:id]/[a:action]/[a:tab]', 'gallery_backend', 'backend:subview:id:action:tab');
  $router->map( 'GET', '/backend/[a:subview]', 'gallery_backend', 'backend:subview');
  $router->map( 'GET', '/backend/[a:subview]/[a:action]', 'gallery_backend', 'backend:subview:action');

  $router->map( 'GET', '/exhibitions', 'gallery_collections', 'exhibitions');
  $router->map( 'GET', '/exhibition/([n:name]~)?[i:id]', 'gallery_collections', 'exhibition:id');
  $router->map( 'GET', '/exhibition/([n:name]~)?[i:id]/[i:item]', 'gallery_collections', 'exhibition:id:item');

  $router->map( 'GET', '/artwork/([n:name]~)?[i:id]', 'gallery_artworks', 'artwork:id');
  $router->map( 'GET', '/item/([n:name]~)?[i:id]', 'gallery_item', 'item:id');
  $router->map( 'GET', '/media/([n:name]~)?[i:id]', 'gallery_media', 'media:id');

  /** Elastic Tools */
  $router->map( 'GET', '/mapping', 'est_mapping', 'ElasticTools Mapping');
  $router->map( 'GET', '/mapping-guide', 'est_mapping_guide', 'ElasticTools Mapping Guide');
  
  
  //$router->map( 'GET', '/profile/([n:name]~)?[i:id]', 'user_profile', 'profile:id');
  //$router->map( 'GET', '/edit-profile/([n:name]~)?[i:id]', 'edit_profile', 'edit-profile:id');
 
  $router->map( 'GET', '/api/[a:action]', 'api', 'api');
  $app->router = $router;
  return $router->match();
}