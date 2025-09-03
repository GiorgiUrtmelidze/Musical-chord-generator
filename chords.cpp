#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vll vector<ll>
#define pb push_back
#define endl '\n'

void print_chords(vll &distances, string chord_type, string &key, ll &note_index, vector<string> &notes) {
    cout << "All " + key + " " + chord_type + " chord inverses" << endl;

    vector<string> chord;
    for (auto &c : distances) {
        chord.pb(notes[(note_index + c) % 12]);
    }

    for (int i = 0; i < chord.size(); ++i) {
        cout << i + 1 << ") " + chord[i] + " " + chord[(i + 1) % chord.size()]+ " " + chord[(i + 2) % chord.size()]
            + " " + (chord_type == "maj7" || chord_type == "maj9" ? chord[(i + 3) % chord.size()] : "")
            + " " + (chord_type == "maj9" ? chord[(i + 4) % chord.size()] : "") << endl;
    }
    cout << '\n';

    chord.clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<string> chord_types = {"maj", "maj7",  "maj9"};
    vector<string> notes_with_flats = {"C", "D♭", "D", "E♭", "E", "F", "G♭", "G", "A♭", "A", "B♭", "B"};
    vector<string> notes_with_sharps = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};

    vector<vector<ll>> chord_type_vector;
    chord_type_vector.pb({0, 4, 7});
    chord_type_vector.pb({0, 4, 7, 11});
    chord_type_vector.pb({0, 4, 7, 11, 14});

    cout << "This program generates all inversed chords based on key (C, D♭, G ...)" << '\n' << endl;
    cout << "Enter key: " << flush;
    cout << '\n';
    string key;
    cin >> key;

    ll note_idx = 0;

    for (int i = 0; i < notes_with_flats.size(); ++i) {
        if (notes_with_flats[i] == key) {
            note_idx = i;
            break;
        }
    }

    for (int i = 0; i < notes_with_sharps.size(); ++i) {
        if (notes_with_sharps[i] == key) {
            note_idx = i;
            break;
        }
    }

    ll idx = 0;
    for (auto &chord_type : chord_types) {
        if (key == "F" || key == "B♭" || key == "E♭" || key == "A♭" || key == "D♭" || key == "G♭" || key == "C♭") {
            print_chords(chord_type_vector[idx], chord_type, key, note_idx, notes_with_flats);
        } else {
            print_chords(chord_type_vector[idx], chord_type, key, note_idx, notes_with_sharps);
        }
        idx++;
    }
    return 0;
}
