<?php


function secure_password_generate ($debug=FALSE) {
    // thank you yaragn!
    $config_NumberOfWords = 2;
    $config_MaxNumberOfDigitBetweenWords = 2;
    $config_DigitsAfterLastWord = FALSE;
    mt_srand ((float) microtime() * 1000000);
    $securePassword = "";
     
    $safeEnglishWords = secure_password_get_words();
    $count = count($safeEnglishWords);
    for ($i=0; $i < $config_NumberOfWords; $i++) {
        $securePassword .= $safeEnglishWords[mt_rand(0,$count)];
        if ($config_DigitsAfterLastWord OR $i + 1 != $config_NumberOfWords) $securePassword .= mt_rand(0,pow(10,$config_MaxNumberOfDigitBetweenWords) -1);
    }
    if ($debug) {
        $combinations = pow($count, $config_NumberOfWords) * pow(10, $config_MaxNumberOfDigitBetweenWords * ($config_NumberOfWords - 1));
        echo $combinations . " number of combinations.<br>";
        echo floor(pow($combinations, 0.5)) . " relative stength.<br>";
        // relative strength principle based on rough mean - root of the number of combinations is the time to find a single password
    }
    return $securePassword;
}

function secure_password_get_words () {
    // slightly modified data from http://www.rick.harrison.net/annex/specialeng.txt - many thanks Rick Harrison!
    $array = Array( 'a', 'able', 'about', 'above', 'accept', 'accident', 'accuse', 'across', 'act',  
'activist', 'actor', 'add', 'administration', 'admit', 'advise', 'affect', 'afraid', 'after', 'again',
'against', 'age', 'agency', 'aggression', 'ago', 'agree', 'agriculture', 'aid', 'aim', 'air',  
'airplane', 'airport', 'alive', 'all', 'ally', 'almost', 'alone', 'along', 'already', 'also',  
'although', 'always', 'ambassador', 'amend', 'ammunition', 'among', 'amount', 'an', 'anarchy',  
'ancient', 'and', 'anger', 'animal', 'anniversary', 'announce', 'another', 'answer', 'any',  
'apologize', 'appeal', 'appear', 'appoint', 'approve', 'area', 'argue', 'arms', 'army', 'around',  
'arrest', 'arrive', 'art', 'artillery', 'as', 'ash', 'ask', 'assist', 'astronaut', 'asylum', 'at',  
'atmosphere', 'atom', 'attack', 'attempt', 'attend', 'automobile', 'autumn', 'awake', 'award', 'away',  
'back', 'bad', 'balance', 'ball', 'balloon', 'ballot', 'ban', 'bank', 'bar', 'base', 'battle', 'be',
'beach', 'beat', 'beauty', 'because', 'become', 'bed', 'beg', 'begin', 'behind', 'believe', 'bell',
'belong', 'below', 'best', 'betray', 'better', 'between', 'big', 'bill', 'bird', 'bite', 'bitter',
'black', 'blame', 'blanket', 'bleed', 'blind', 'block', 'blood', 'blow', 'blue', 'boat', 'body',
'boil', 'bomb', 'bone', 'book', 'border', 'born', 'borrow', 'both', 'bottle', 'bottom', 'box',
'boy', 'brain', 'brave', 'bread', 'break', 'breathe', 'bridge', 'brief', 'bright', 'bring',
'broadcast', 'brother', 'brown', 'build', 'bullet', 'burn', 'burst', 'bury', 'bus', 'business',
'busy', 'but', 'buy', 'by', 'cabinet', 'call', 'calm', 'camera', 'campaign', 'can', 'cancel',
'cancer', 'candidate', 'cannon', 'capital', 'capture', 'car', 'care', 'careful', 'carry', 'case',
'cat', 'catch', 'cattle', 'cause', 'ceasefire', 'celebrate', 'cell', 'center', 'century',
'ceremony', 'chairman', 'champion', 'chance', 'change', 'charge', 'chase', 'cheat', 'check',
'cheer', 'chemicals', 'chieg', 'child', 'choose', 'church', 'circle', 'citizen', 'city',
'civil', 'civilian', 'clash', 'clean', 'clear', 'clergy', 'climb', 'clock', 'close', 'cloth',
'clothes', 'cloud', 'coal', 'coalition', 'coast', 'coffee', 'cold', 'collect', 'colony', 'color',
'come', 'comedy', 'command', 'comment', 'committee', 'common', 'communicate', 'company', 'compete',
'complete', 'compromise', 'computer', 'concern', 'condemn', 'condition', 'conference', 'confirm',
'conflict', 'congratulate', 'congress', 'connect', 'conservative', 'consider', 'contain',
'continent', 'continue', 'control', 'convention', 'cook', 'cool', 'cooperate', 'copy', 'correct',
'cost', 'costitution', 'cotton', 'count', 'country', 'court', 'cover', 'cow',
'coward', 'crash', 'create', 'creature', 'credit', 'crew', 'crime', 'criminal', 'crisis',
'criticize', 'crops', 'cross', 'crowd', 'cruel', 'crush', 'cry', 'culture', 'cure', 'current',
'custom', 'cut', 'dam', 'damage', 'dance', 'danger', 'dark', 'date', 'daughter', 'day', 'dead',
'deaf', 'deal', 'debate', 'decide', 'declare', 'deep', 'defeat', 'defend', 'deficit', 'degree',
'delay', 'delegate', 'demand', 'democracy', 'demonstrate', 'denounce', 'deny', 'depend', 'deplore',
'deploy', 'describe', 'desert', 'design', 'desire', 'destroy', 'details', 'develop', 'device', 'dictator', 'die',  
'different', 'difficult', 'dig', 'dinner', 'diplomat', 'direct', 'direction', 'dirty', 'disappear', 'disarm', 'discover',  
'discuss', 'disease', 'dismiss', 'dispute', 'dissident', 'distance', 'distant', 'dive', 'divide', 'do', 'doctor', 'document',
'dollar', 'door', 'down', 'draft', 'dream', 'drink', 'drive', 'drown', 'drugs', 'dry', 'during', 'dust', 'duty', 'each',  
'early', 'earn', 'earth', 'earthquake', 'ease', 'east', 'easy', 'eat', 'economy', 'edge', 'educate', 'effect', 'effort',  
'egg', 'either', 'elect', 'electricity', 'electron', 'element', 'embassy', 'emergency', 'emotion', 'employ', 'empty', 'end',  
'enemy', 'energy', 'enforce', 'engine', 'engineer', 'enjoy', 'enough', 'enter', 'eqipment', 'equal', 'escape', 'especially',  
'establish', 'even', 'event', 'ever', 'every', 'evidence', 'evil', 'evironment', 'exact', 'examine', 'example', 'excellent',
'except', 'exchange', 'excite', 'excuse', 'execute', 'exile', 'exist', 'expand', 'expect', 'expel', 'experiment', 'expert',  
'explain', 'explode', 'explore', 'export', 'express', 'extend', 'extra', 'extreme', 'face', 'fact', 'factory', 'fail',  
'fair', 'fall', 'family', 'famous', 'fanatic', 'far', 'farm', 'fast', 'fat', 'father', 'fear', 'feast', 'federal', 'feed',  
'feel', 'female', 'fertile', 'few', 'field', 'fierce', 'fight', 'fill', 'film', 'final', 'find', 'fine', 'finish', 'fire',  
'firm', 'first', 'fish', 'fix', 'flag', 'flat', 'flee', 'float', 'flood', 'floor', 'flow', 'flower', 'fluid', 'fly', 'fog',  
'follow', 'food', 'fool', 'foot', 'for', 'force', 'foreign', 'forget', 'forgive', 'form', 'former', 'forward', 'free',  
'freeze', 'fresh', 'friend', 'frighten', 'from', 'front', 'fruit', 'fuel', 'funeral', 'furious', 'future', 'gain', 'game',  
'gas', 'gather', 'general', 'gentle', 'get', 'gift', 'girl', 'give', 'glass', 'go', 'goal', 'God', 'gold', 'good',  
'good-bye', 'goods', 'govern', 'government', 'grain', 'grandfather', 'grandmother', 'grass', 'gray', 'great', 'green',  
'grind', 'ground', 'group', 'grow', 'guarantee', 'guard', 'guerilla', 'guide', 'guilty', 'gun', 'hair', 'half', 'halt',  
'hang', 'happen', 'happy', 'harbor', 'hard', 'harm', 'hat', 'hate', 'he', 'head', 'headquarters', 'health', 'hear', 'heart',
'heat', 'heavy', 'helicopter', 'help', 'here', 'hero', 'hide', 'high', 'hijack', 'hill', 'history', 'hit', 'hold', 'hole',
'holiday', 'holy', 'home', 'honest', 'honor', 'hope', 'horrible', 'horse', 'hospital', 'hostage', 'hostile', 'hostilities',
'hot', 'hotel', 'hour', 'house', 'how', 'however', 'huge', 'human', 'humor', 'hunger', 'hunt', 'hurry', 'hurt', 'husband',  
'I', 'ice', 'idea', 'if', 'illegal', 'imagine', 'immediate', 'import', 'important', 'improve', 'in', 'incident', 'incite',  
'include', 'increase', 'independent', 'industry', 'inflation', 'influence', 'inform', 'injure', 'innocent', 'insane',  
'insect', 'inspect', 'instead', 'instrument', 'insult', 'intelligent', 'intense', 'interest', 'interfere', 'international',  
'intervene', 'invade', 'invent', 'invest', 'investigate', 'invite', 'involve', 'iron', 'island', 'issue', 'it', 'jail',  
'jewel', 'job', 'join', 'joint', 'joke', 'judge', 'jump', 'jungle', 'jury', 'just', 'keep', 'kick', 'kidnap', 'kill', 'kind',
'kiss', 'knife', 'know', 'labor', 'laboratory', 'lack', 'lake', 'land', 'language', 'large', 'last', 'late', 'laugh',  
'launch', 'law', 'lead', 'leak', 'learn', 'leave', 'left', 'legal', 'lend', 'less', 'let', 'letter', 'level', 'liberal',  
'lie', 'life', 'light', 'lightning', 'like', 'limit', 'line', 'link', 'liquid', 'list', 'listen', 'little', 'live', 'load',  
'local', 'lonely', 'long', 'look', 'lose', 'loud', 'love', 'low', 'loyal', 'luck', 'machine', 'mad', 'mail', 'main', 'major',
'majority', 'make', 'male', 'man', 'map', 'march', 'mark', 'marker', 'mass', 'material', 'may', 'mayor', 'mean', 'measure',  
'meat', 'medicine', 'meet', 'melt', 'member', 'memorial', 'memory', 'mercenary', 'mercy', 'message', 'metal', 'method',  
'microscope', 'middle', 'militant', 'military', 'milk', 'mind', 'mine', 'mineral', 'minister', 'minor', 'minority', 'minute',
'miss', 'missile', 'missing', 'mistake', 'mix', 'mob', 'moderate', 'modern', 'money', 'month', 'moon', 'more', 'morning',  
'most', 'mother', 'motion', 'mountain', 'mourn', 'move', 'much', 'murder', 'music', 'must', 'mystery', 'naked', 'name',  
'nation', 'navy', 'near', 'necessary', 'need', 'negotiate', 'neither', 'nerve', 'neutral', 'never', 'new', 'news', 'next',  
'nice', 'night', 'no', 'noise', 'nominate', 'noon', 'normal', 'north', 'not', 'note', 'nothing', 'now', 'nowhere', 'nuclear',
'number', 'nurse', 'obey', 'object', 'observe', 'occupy', 'ocean', 'of', 'off', 'offensive', 'offer', 'officer', 'official',
'often', 'oil', 'old', 'on', 'once', 'only', 'open', 'operate', 'opinion', 'oppose', 'opposite', 'oppress', 'or', 'orbit',  
'orchestra', 'order', 'organize', 'other', 'oust', 'out', 'over', 'overthrow', 'owe', 'own', 'pain', 'paint', 'palace',  
'pamphlet', 'pan', 'paper', 'parachute', 'parade', 'pardon', 'parent', 'parliament', 'part', 'party', 'pass', 'passenger',  
'passport', 'past', 'path', 'pay', 'peace', 'people', 'percent', 'perfect', 'perhaps', 'period', 'permanent', 'permit',  
'person', 'physics', 'piano', 'picture', 'piece', 'pilot', 'pipe', 'pirate', 'place', 'planet', 'plant', 'play', 'please',  
'plenty', 'plot', 'poem', 'point', 'poison', 'police', 'policy', 'politics', 'pollute', 'poor', 'popular', 'population',  
'port', 'position', 'possess', 'possible', 'postpone', 'pour', 'power', 'praise', 'pray', 'pregnant', 'prepare', 'present',  
'president', 'press', 'pressure', 'prevent', 'price', 'priest', 'prison', 'private', 'prize', 'probably', 'problem',  
'produce', 'professor', 'program', 'progress', 'project', 'promise', 'propaganda', 'property', 'propose', 'protect',  
'protest', 'proud', 'prove', 'provide', 'public', 'publication', 'publish', 'pull', 'pump', 'punish', 'purchase', 'pure',  
'purpose', 'push', 'put', 'question', 'quick', 'quiet', 'rabbi', 'race', 'radar', 'radiation', 'radio', 'raid', 'railroad',  
'rain', 'raise', 'rapid', 'rare', 'rate', 'reach', 'read', 'ready', 'real', 'realistic', 'reason', 'reasonable', 'rebel',  
'receive', 'recent', 'recession', 'recognize', 'record', 'red', 'reduce', 'reform', 'refugee', 'refuse', 'regret',  
'relations', 'release', 'religion', 'remain', 'remember', 'remove', 'repair', 'repeat', 'report', 'repress', 'request',  
'rescue', 'resign', 'resolution', 'responsible', 'rest', 'restrain', 'restrict', 'result', 'retire', 'return', 'revolt',  
'rice', 'rich', 'ride', 'right', 'riot', 'rise', 'river', 'road', 'rob', 'rock', 'rocket', 'roll', 'room', 'root', 'rope',  
'rough', 'round', 'rub', 'rubber', 'ruin', 'rule', 'run', 'sabotage', 'sacrifice', 'sad', 'safe', 'sail', 'salt', 'same',  
'satellite', 'satisfy', 'save', 'say', 'school', 'science', 'scream', 'sea', 'search', 'season', 'seat', 'second', 'secret',  
'security', 'see', 'seek', 'seem', 'seize', 'self', 'sell', 'senate', 'send', 'sense', 'sentence', 'separate', 'series',  
'serious', 'sermon', 'serve', 'set', 'settle', 'several', 'severe', 'sex', 'shake', 'shape', 'share', 'sharp', 'she', 'shell',  
'shine', 'ship', 'shock', 'shoe', 'shoot', 'short',
'should', 'shout', 'show', 'shrink', 'shut', 'sick', 'side',
'sign', 'signal', 'silence', 'silver', 'similar', 'simple', 'since', 'sing', 'sink', 'sister', 'sit', 'situation', 'size',  
'skeleton', 'skill', 'skull', 'sky', 'slave', 'sleep', 'slide', 'slow', 'small', 'smash', 'smell', 'smile', 'smoke',  
'smooth', 'snow', 'so', 'social', 'soft', 'soldier', 'solid', 'solve', 'some', 'son', 'soon', 'sorry', 'sort', 'sound',  
'south', 'space', 'speak', 'special', 'speed', 'spend', 'spill', 'spilt', 'spirit', 'split', 'sports', 'spread', 'spring',  
'spy', 'stab', 'stamp', 'stand', 'star', 'start', 'starve', 'state', 'station', 'statue', 'stay', 'steal', 'steam', 'steel',  
'step', 'stick', 'still', 'stomach', 'stone', 'stop', 'store', 'storm', 'story', 'stove', 'straight', 'strange', 'street',  
'stretch', 'strike', 'strong', 'struggle', 'stubborn', 'study', 'stupid', 'submarine', 'substance', 'substitute',  
'subversion', 'succeed', 'such', 'sudden', 'suffer', 'sugar', 'summer', 'sun', 'supervise', 'supply', 'support', 'suppose',  
'suppress', 'sure', 'surplus', 'surprise', 'surrender', 'surround', 'survive', 'suspect', 'suspend', 'swallow', 'swear',  
'sweet', 'swim', 'sympathy', 'system', 'take', 'talk', 'tall', 'tank', 'target', 'task', 'taste', 'tax', 'teach', 'team',  
'tear', 'tears', 'technical', 'telephone', 'telescope', 'television', 'tell', 'temperature', 'temporary', 'tense', 'term',  
'terrible', 'territory', 'terror', 'test', 'textiles', 'than', 'thank', 'that', 'the', 'theater', 'then', 'there', 'thick',  
'thin', 'thing', 'think', 'third', 'this', 'threaten', 'through', 'throw', 'tie', 'time', 'tired', 'tissue', 'to', 'today',  
'together', 'tomorrow', 'tonight', 'too', 'tool', 'top', 'torture', 'touch', 'toward', 'town', 'trade', 'tradition',  
'tragic', 'train', 'traitor', 'transport', 'trap', 'travel', 'treason', 'treasure', 'treat', 'treaty', 'tree', 'trial',  
'tribe', 'trick', 'trip', 'troops', 'trouble', 'truce', 'truck', 'trust', 'try', 'turn', 'under', 'understand', 'unite',  
'universe', 'university', 'unless', 'until', 'up', 'urge', 'urgent', 'use', 'usual', 'valley', 'value', 'vehicle', 'version',  
'veto', 'vicious', 'victim', 'victory', 'village', 'violate', 'violence', 'violin', 'virus', 'visit', 'voice', 'volcano',  
'vote', 'voyage', 'wages', 'wait', 'walk', 'wall', 'want', 'war', 'warm', 'warn', 'wash', 'waste', 'watch', 'water', 'wave',  
'way', 'weak', 'wealth', 'weapon', 'wear', 'weather', 'weigh', 'welcome', 'well', 'west', 'wet', 'what', 'wheat', 'wheel',  
'when', 'where', 'which', 'while', 'white', 'who', 'why', 'wide', 'wife', 'wild', 'will', 'willing', 'win', 'wind', 'window',
'wire', 'wise', 'wish', 'with', 'withdraw', 'without', 'woman', 'wonder', 'wood', 'woods', 'word', 'work', 'world', 'worry',
'worse', 'wound', 'wreck', 'write', 'wrong', 'year', 'yellow', 'yes', 'yesterday', 'yet', 'you', 'young');
    return $array;
}