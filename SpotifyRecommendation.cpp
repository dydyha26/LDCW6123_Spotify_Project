// ============================================================
// Spotify Music Recommendation Assistant
// LDCW6123 Group Project - Part 2 (Interactive Program)
//
// Concept : a simplified version of Spotify's recommendation idea.
// Inputs  : name, genre (required), mood (optional)
// Outputs : recommended artist, song, genre, mood, description
// Logic   : switch (genre) + if/else (mood)
// ============================================================
#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Holds everything we show the user about one recommendation
struct Recommendation {
    string artist;
    string song;
    string genre;
    string mood;
    string description;
};

const string LINE = "  ==================================================";

// ---------------------------------------------------------
// Input helpers
// ---------------------------------------------------------

// Ask for a whole number between low and high.
// Keeps asking until the user types a valid number.
int readChoice(const string &prompt, int low, int high) {
    int choice;
    while (true) {
        cout << prompt;
        if (cin >> choice && choice >= low && choice <= high) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        }
        cout << "  [!] Invalid input. Please enter a number from "
             << low << " to " << high << ".\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Ask a yes/no question. Returns true for 'y', false for 'n'.
bool readYesNo(const string &prompt) {
    char answer;
    while (true) {
        cout << prompt;
        cin >> answer;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (answer == 'y' || answer == 'Y') return true;
        if (answer == 'n' || answer == 'N') return false;
        cout << "  [!] Please type y or n.\n";
    }
}

// ---------------------------------------------------------
// Menus
// ---------------------------------------------------------
void showHeader() {
    cout << "\n" << LINE << "\n"
         << "        SPOTIFY MUSIC RECOMMENDATION ASSISTANT\n"
         << LINE << "\n"
         << "  Tell me what you like and I will suggest a song.\n"
         << "  Type the number of your choice and press Enter.\n";
}

void showGenreMenu() {
    cout << "\n  Step 1: Choose your genre\n"
         << "  --------------------------------------------------\n"
         << "    1. Pop\n"
         << "    2. Hip-Hop\n"
         << "    3. Rock\n"
         << "    4. R&B\n"
         << "    5. Indie\n"
         << "    6. K-Pop\n"
         << "    7. Malay Pop\n";
}

void showMoodMenu() {
    cout << "\n  Step 2: Choose your mood (optional)\n"
         << "  --------------------------------------------------\n"
         << "    1. Happy\n"
         << "    2. Sad\n"
         << "    3. Energetic\n"
         << "    4. Chill\n"
         << "    5. Skip (surprise me)\n";
}

// ---------------------------------------------------------
// Recommendation logic
// ---------------------------------------------------------

// Small helper so each song is one neat line below
void setSong(Recommendation &r, const string &artist,
             const string &song, const string &description) {
    r.artist = artist;
    r.song = song;
    r.description = description;
}

string moodName(int mood) {
    switch (mood) {
        case 1:  return "Happy";
        case 2:  return "Sad";
        case 3:  return "Energetic";
        case 4:  return "Chill";
        default: return "Surprise me";
    }
}

// genre: 1-7, mood: 1-4 (5 = skipped -> default song for that genre)
Recommendation getRecommendation(int genre, int mood) {
    Recommendation r;
    r.mood = moodName(mood);

    switch (genre) {
    case 1: // ---------------- Pop ----------------
        r.genre = "Pop";
        if (mood == 1)      setSong(r, "Dua Lipa",      "Levitating",       "Disco-inspired pop that lifts any mood.");
        else if (mood == 2) setSong(r, "Adele",         "Someone Like You", "A powerful piano ballad about letting go.");
        else if (mood == 3) setSong(r, "Taylor Swift",  "Shake It Off",     "A high-energy anthem about shrugging off negativity.");
        else if (mood == 4) setSong(r, "Billie Eilish", "Ocean Eyes",       "Soft, dreamy vocals over a gentle beat.");
        else                setSong(r, "The Weeknd",    "Blinding Lights",  "Retro synth-pop with a fast, driving rhythm.");
        break;

    case 2: // ------------- Hip-Hop ---------------
        r.genre = "Hip-Hop";
        if (mood == 1)      setSong(r, "OutKast",        "Hey Ya!",       "A funky, feel-good track you can't sit still to.");
        else if (mood == 2) setSong(r, "Eminem",         "Mockingbird",   "An emotional song about family and love.");
        else if (mood == 3) setSong(r, "Eminem",         "Lose Yourself", "An intense track about seizing your one shot.");
        else if (mood == 4) setSong(r, "Kid Cudi",       "Day 'n' Nite",  "Laid-back, moody hip-hop with a hypnotic beat.");
        else                setSong(r, "Kendrick Lamar", "HUMBLE.",       "Hard-hitting hip-hop with sharp lyrics and a bold beat.");
        break;

    case 3: // ---------------- Rock ---------------
        r.genre = "Rock";
        if (mood == 1)      setSong(r, "Queen",       "Don't Stop Me Now",  "A joyful, fast-paced classic full of confidence.");
        else if (mood == 2) setSong(r, "Linkin Park", "Numb",               "A heavy track about pressure and expectations.");
        else if (mood == 3) setSong(r, "AC/DC",       "Thunderstruck",      "A loud, electrifying hard-rock anthem.");
        else if (mood == 4) setSong(r, "Coldplay",    "Yellow",             "A warm, mellow song with soaring guitars.");
        else                setSong(r, "Queen",       "Bohemian Rhapsody",  "An epic, genre-bending rock masterpiece.");
        break;

    case 4: // ---------------- R&B ----------------
        r.genre = "R&B";
        if (mood == 1)      setSong(r, "Beyonce",       "Crazy in Love", "Bold, joyful R&B with a famous horn hook.");
        else if (mood == 2) setSong(r, "SZA",           "Kill Bill",     "A moody, honest song about love and jealousy.");
        else if (mood == 3) setSong(r, "Usher",         "Yeah!",         "A club-ready track built for the dance floor.");
        else if (mood == 4) setSong(r, "Daniel Caesar", "Get You",       "Smooth and soulful. Perfect for winding down.");
        else                setSong(r, "SZA",           "Good Days",     "A calm, hopeful song with silky vocals.");
        break;

    case 5: // --------------- Indie ---------------
        r.genre = "Indie";
        if (mood == 1)      setSong(r, "MGMT",           "Electric Feel",                        "Quirky, groovy indie-pop with a funky bassline.");
        else if (mood == 2) setSong(r, "Bon Iver",       "Skinny Love",                          "A raw, quiet song about a fading relationship.");
        else if (mood == 3) setSong(r, "Arctic Monkeys", "I Bet You Look Good on the Dancefloor", "Fast, punchy indie rock from the first second.");
        else if (mood == 4) setSong(r, "Beach House",    "Space Song",                           "Dreamy, floating synths for a calm evening.");
        else                setSong(r, "Arctic Monkeys", "Do I Wanna Know?",                     "A slow, heavy riff with a dark, cool atmosphere.");
        break;

    case 6: // --------------- K-Pop ---------------
        r.genre = "K-Pop";
        if (mood == 1)      setSong(r, "BTS",      "Dynamite",         "Bright, disco-pop energy that is instantly catchy.");
        else if (mood == 2) setSong(r, "BTS",      "Spring Day",       "A gentle, emotional song about missing someone.");
        else if (mood == 3) setSong(r, "BLACKPINK","Kill This Love",   "Loud brass and a hard-hitting beat with big attitude.");
        else if (mood == 4) setSong(r, "IU",       "Through the Night","A soft, warm ballad that feels like a lullaby.");
        else                setSong(r, "BTS",      "Butter",           "Smooth, confident pop with a groovy bassline.");
        break;

    default: // ------------ Malay Pop -------------
        r.genre = "Malay Pop";
        if (mood == 1)      setSong(r, "Siti Nurhaliza", "Bukan Cinta Biasa",     "A romantic, uplifting hit by Malaysia's pop icon.");
        else if (mood == 2) setSong(r, "Ziana Zain",     "Terlerai Kasih",        "A classic ballad about a broken relationship.");
        else if (mood == 3) setSong(r, "M. Nasir",       "Mentera Semerah Padi",  "A powerful, dramatic Malaysian classic.");
        else if (mood == 4) setSong(r, "Yuna",           "Crush",                 "Soft, soulful and relaxed. Malaysia's global export.");
        else                setSong(r, "Siti Nurhaliza", "Cindai",                "A timeless, elegant song loved across generations.");
        break;
    }
    return r;
}

// ---------------------------------------------------------
// Output
// ---------------------------------------------------------
void printRecommendation(const string &name, const Recommendation &r) {
    cout << "\n" << LINE << "\n"
         << "   Hi " << name << ", here is your recommendation!\n"
         << LINE << "\n"
         << "   Artist      : " << r.artist << "\n"
         << "   Song        : " << r.song << "\n"
         << "   Genre       : " << r.genre << "\n"
         << "   Mood        : " << r.mood << "\n"
         << "   Description : " << r.description << "\n"
         << LINE << "\n";
}

// ---------------------------------------------------------
// Main
// ---------------------------------------------------------
int main() {
    string name;
    int count = 0;              // how many recommendations were given

    showHeader();

    cout << "\n  Enter your name: ";
    getline(cin, name);
    if (name.empty()) name = "Listener";     // fallback for empty input

    do {
        showGenreMenu();
        int genre = readChoice("\n  Enter genre (1-7): ", 1, 7);

        showMoodMenu();
        int mood = readChoice("\n  Enter mood (1-5): ", 1, 5);

        Recommendation rec = getRecommendation(genre, mood);
        printRecommendation(name, rec);
        count++;

    } while (readYesNo("\n  Would you like another recommendation? (y/n): "));

    cout << "\n" << LINE << "\n"
         << "  Thanks for using the assistant, " << name << "!\n"
         << "  Recommendations given: " << count << ". Enjoy the music!\n"
         << LINE << "\n\n";
    return 0;
}
